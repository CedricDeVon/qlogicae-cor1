#pragma once

#include "abstract_class.hpp"
#include "onnx_api_manager_configurations.hpp"

namespace
	QLogicae::Cor::V1
{
    class
		OnnxApiManager :
			public AbstractClass<OnnxApiManagerConfigurations>
    {
    public:		
		Ort::Env
			env_ { ORT_LOGGING_LEVEL_WARNING, "default" };

		Ort::Session
			session_ { nullptr };

		Ort::SessionOptions
			session_options_ {};

		std::vector<std::string>
			input_names_str_;

		std::vector<const char*>
			input_names_ptrs_;

		std::vector<std::vector<int64_t>>
			input_shapes_;

		std::vector<std::string>
			output_names_str_;

		std::vector<const char*>
			output_names_ptrs_;

		std::vector<const char*>
			input_name_ptrs_runtime_;

		std::vector<Ort::Value>
			input_tensors_;

		std::vector<Ort::Value>
			output_tensors_;

		std::vector<std::vector<float>>
			numeric_buffers_;

		std::vector<std::vector<std::string>>
			string_buffers_;

		OnnxApiManager();

		~OnnxApiManager();

		bool
			setup();

		std::unordered_map<std::string, std::vector<std::string>>
			infer_via_strings(
				const std::unordered_map<std::string, std::vector<std::vector<std::string>>>&
					inputs
			);

		bool
			prepare_string_inputs(
				const std::unordered_map<std::string, std::vector<std::vector<std::string>>>&
					inputs
			);

		std::unordered_map<std::string, std::vector<std::string>>
			collect_string_outputs();


		std::vector<int64_t>
			resolve_shape(
				const size_t&
					input_index,
				const size_t&
					batch_size,
				const size_t&
					feature_size
			);

		bool
			run_session();

		template<typename Type> std::unordered_map<std::string, std::span<const Type>>
			infer_via_numerics(
				const std::unordered_map<std::string, std::vector<std::vector<Type>>>&
					inputs
			);

		template<typename Type> bool
			prepare_numeric_inputs(
				const std::unordered_map<std::string, std::vector<std::vector<Type>>>&
					inputs
			);

		template<typename Type> std::unordered_map<std::string, std::span<const Type>>
			collect_numeric_outputs();
    };

	template<typename Type> std::unordered_map<std::string, std::span<const Type>>
		OnnxApiManager
			::infer_via_numerics(
				const std::unordered_map<std::string, std::vector<std::vector<Type>>>&
					inputs
			)
	{
			prepare_numeric_inputs(inputs);
			run_session();

			return collect_numeric_outputs<Type>();
	}

	template<typename Type> bool
		OnnxApiManager
			::prepare_numeric_inputs(
				const std::unordered_map<std::string, std::vector<std::vector<Type>>>&
					inputs
			)
	{
		input_tensors_.clear();
		input_name_ptrs_runtime_.clear();
		numeric_buffers_.clear();

		for (size_t i = 0; i < input_names_str_.size(); ++i) {
			const auto& name = input_names_str_[i];
			auto it = inputs.find(name);
			if (it == inputs.end())
				return false;

			const auto& batch = it->second;
			if (batch.empty())
				return false;

			size_t batch_size = batch.size();
			size_t feature_size = batch[0].size();

			for (const auto& sample : batch)
				if (sample.size() != feature_size)
					return false;

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
				Ort::Value::CreateTensor<Type>(
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

	template<typename Type> std::unordered_map<std::string, std::span<const Type>>
		OnnxApiManager
			::collect_numeric_outputs()
	{
		std::unordered_map<std::string, std::span<const Type>> results;

		for (size_t i = 0; i < output_tensors_.size(); ++i)
		{
			auto type_info =
				output_tensors_[i].GetTensorTypeAndShapeInfo();

			if (type_info.GetElementType() !=
				Ort::TypeToTensorType<Type>::type)
				return {};

			Type* data = output_tensors_[i].GetTensorMutableData<Type>();
			size_t count = type_info.GetElementCount();

			results[output_names_str_[i]] =
				std::span<const Type>(data, count);
		}

		return results;
	}
}
