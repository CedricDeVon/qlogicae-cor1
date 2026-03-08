#pragma once

#include "abstract_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    struct
		OnnxApiManagerConfigurations :
			AbstractConfigurations<OnnxApiManagerConfigurations>
    {
	public:
		std::string
			model_path =
				default_configurations
					.model_path;

		bool
			enable_cuda =
				default_configurations
					.enable_cuda;

		int
			device_id =
				default_configurations
					.device_id;

		static OnnxApiManagerConfigurations
			initial_configurations;

		static OnnxApiManagerConfigurations
			default_configurations;

		OnnxApiManagerConfigurations();
    };    
}

/*


class OnnxSessionStream {
public:
	struct ModelConfig {
		std::string model_path;
		bool enable_cuda = false;
		std::optional<int> device_id;
	};

	OnnxSessionStream(const ModelConfig& config) :
		env_ { ORT_LOGGING_LEVEL_WARNING, "MyApp" },
		session_{ nullptr },
		session_options_ {}
	{
		init(config);
	}

	template<typename T>
	std::unordered_map<std::string, std::span<const T>>
		infer_numeric(const std::unordered_map<std::string,
			std::vector<std::vector<T>>>& inputs)
	{
		static_assert(std::is_arithmetic_v<T>,
			"Numeric inference supports arithmetic types only.");

		prepare_numeric_inputs(inputs);
		run_session();

		return collect_numeric_outputs<T>();
	}

	std::unordered_map<std::string, std::vector<std::string>>
		infer_string(const std::unordered_map<std::string,
			std::vector<std::vector<std::string>>>& inputs)
	{
		prepare_string_inputs(inputs);
		run_session();
		return collect_string_outputs();
	}

	const std::vector<std::string>& input_names() const noexcept {
		return input_names_str_;
	}

	const std::vector<std::string>& output_names() const noexcept {
		return output_names_str_;
	}

private:
	template<typename T>
	void prepare_numeric_inputs(
		const std::unordered_map<std::string, std::vector<std::vector<T>>>& inputs)
	{
		input_tensors_.clear();
		input_name_ptrs_runtime_.clear();
		numeric_buffers_.clear();

		for (size_t i = 0; i < input_names_str_.size(); ++i) {
			const auto& name = input_names_str_[i];
			auto it = inputs.find(name);
			if (it == inputs.end())
				throw std::runtime_error("Missing input: " + name);

			const auto& batch = it->second;
			if (batch.empty())
				throw std::runtime_error("Empty batch for input: " + name);

			size_t batch_size = batch.size();
			size_t feature_size = batch[0].size();

			for (const auto& sample : batch)
				if (sample.size() != feature_size)
					throw std::runtime_error("Inconsistent feature sizes.");

			size_t total = batch_size * feature_size;
			numeric_buffers_.emplace_back(total);
			auto& buffer = numeric_buffers_.back();

			for (size_t b = 0; b < batch_size; ++b)
				std::copy(batch[b].begin(), batch[b].end(),
					buffer.begin() + b * feature_size);

			std::vector<int64_t> shape = resolve_shape(i, batch_size, feature_size);

			const Ort::MemoryInfo mem_info = Ort::MemoryInfo::CreateCpu(
				OrtArenaAllocator, OrtMemTypeDefault);

			input_tensors_.emplace_back(
				Ort::Value::CreateTensor<T>(
					mem_info,
					buffer.data(),
					total,
					shape.data(),
					shape.size()
				)
			);

			input_name_ptrs_runtime_.push_back(input_names_ptrs_[i]);
		}
	}


	void prepare_string_inputs(
		const std::unordered_map<std::string, std::vector<std::vector<std::string>>>& inputs)
	{
		input_tensors_.clear();
		input_name_ptrs_runtime_.clear();

		Ort::AllocatorWithDefaultOptions allocator;

		for (size_t i = 0; i < input_names_str_.size(); ++i) {
			const auto& name = input_names_str_[i];
			auto it = inputs.find(name);
			if (it == inputs.end())
				throw std::runtime_error("Missing input: " + name);

			const auto& batch = it->second;
			size_t batch_size = batch.size();
			size_t feature_size = batch[0].size();

			std::vector<int64_t> shape = resolve_shape(i, batch_size, feature_size);


			Ort::Value input_tensor = Ort::Value::CreateTensor(
				allocator,
				shape.data(),
				shape.size(),
				ONNX_TENSOR_ELEMENT_DATA_TYPE_STRING
			);

			std::vector<const char*> raw_ptrs;
			for (const auto& row : batch)
				for (const auto& str : row)
					raw_ptrs.push_back(str.c_str());

			input_tensor.FillStringTensor(raw_ptrs.data(), raw_ptrs.size());

			input_tensors_.push_back(std::move(input_tensor));
			input_name_ptrs_runtime_.push_back(input_names_ptrs_[i]);
		}
	}

	void run_session()
	{
		output_tensors_ = session_.Run(
			Ort::RunOptions{},
			input_name_ptrs_runtime_.data(),
			input_tensors_.data(),
			input_tensors_.size(),
			output_names_ptrs_.data(),
			output_names_ptrs_.size()
		);
	}

	template<typename T>
	std::unordered_map<std::string, std::span<const T>>
		collect_numeric_outputs()
	{
		std::unordered_map<std::string, std::span<const T>> results;

		for (size_t i = 0; i < output_tensors_.size(); ++i) {

			auto type_info =
				output_tensors_[i].GetTensorTypeAndShapeInfo();

			if (type_info.GetElementType() !=
				Ort::TypeToTensorType<T>::type)
				throw std::runtime_error("Output type mismatch.");

			T* data = output_tensors_[i].GetTensorMutableData<T>();
			size_t count = type_info.GetElementCount();

			results[output_names_str_[i]] =
				std::span<const T>(data, count);
		}

		return results;
	}

	std::unordered_map<std::string, std::vector<std::string>>
		collect_string_outputs()
	{
		std::unordered_map<std::string,
			std::vector<std::string>> results;

		for (size_t i = 0; i < output_tensors_.size(); ++i) {

			size_t count =
				output_tensors_[i]
				.GetTensorTypeAndShapeInfo()
				.GetElementCount();

			size_t total_length =
				output_tensors_[i].GetStringTensorDataLength();

			std::vector<char> buffer(total_length);
			std::vector<size_t> offsets(count);

			output_tensors_[i].GetStringTensorContent(
				buffer.data(),
				total_length,
				offsets.data(),
				count
			);

			std::vector<std::string> strings(count);
			for (size_t j = 0; j < count; ++j) {
				size_t start = offsets[j];
				size_t end = (j + 1 < count)
					? offsets[j + 1]
					: total_length;
				strings[j] =
					std::string(buffer.data() + start,
						end - start);
			}

			results[output_names_str_[i]] = std::move(strings);
		}

		return results;
	}

	std::vector<int64_t>
		resolve_shape(size_t input_index,
			size_t batch_size,
			size_t feature_size)
	{
		std::vector<int64_t> shape =
			input_shapes_[input_index];

		shape[0] = static_cast<int64_t>(batch_size);

		int64_t known_product = 1;
		for (size_t i = 1; i < shape.size(); ++i)
			known_product *= shape[i];

		if (known_product == 0)
			throw std::runtime_error("Invalid model shape.");

		if (known_product != static_cast<int64_t>(feature_size))
			shape.back() =
			static_cast<int64_t>(feature_size /
				(known_product /
					shape.back()));

		return shape;
	}






	void init(const ModelConfig& config)
	{
		session_options_.SetIntraOpNumThreads(1);
		session_options_.SetGraphOptimizationLevel(
			ORT_DISABLE_ALL
		);

		#ifdef USE_CUDA
		if (config.enable_cuda) {
			OrtCUDAProviderOptions cuda_opts{};
			if (config.device_id)
				cuda_opts.device_id = *config.device_id;
			session_options_
				.AppendExecutionProvider_CUDA(cuda_opts);
		}
		#endif

		std::wstring wpath(
			config.model_path.begin(),
			config.model_path.end());

		session_ = Ort::Session(env_, wpath.c_str(),
			session_options_);

		Ort::AllocatorWithDefaultOptions allocator;

		size_t num_inputs = session_.GetInputCount();
		input_names_str_.resize(num_inputs);
		input_names_ptrs_.resize(num_inputs);
		input_shapes_.resize(num_inputs);

		for (size_t i = 0; i < num_inputs; ++i) {

			auto name =
				session_.GetInputNameAllocated(i, allocator);

			input_names_str_[i] = name.get();
			input_names_ptrs_[i] =
				input_names_str_[i].c_str();

			auto info =
				session_.GetInputTypeInfo(i)
				.GetTensorTypeAndShapeInfo();

			input_shapes_[i] = info.GetShape();

			for (auto& d : input_shapes_[i])
				if (d < 0) d = 1;
		}

		size_t num_outputs = session_.GetOutputCount();
		output_names_str_.resize(num_outputs);
		output_names_ptrs_.resize(num_outputs);

		for (size_t i = 0; i < num_outputs; ++i) {

			auto name =
				session_.GetOutputNameAllocated(i,
					allocator);

			output_names_str_[i] = name.get();
			output_names_ptrs_[i] =
				output_names_str_[i].c_str();
		}
	}
};


*/