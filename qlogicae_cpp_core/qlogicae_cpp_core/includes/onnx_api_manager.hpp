#pragma once

#include "abstract_class.hpp"
#include "singleton_manager.hpp"
#include "onnx_api_manager_configurations.hpp"

namespace
	QLogicaeCppCore
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

        static OnnxApiManager&
            singleton;

		OnnxApiManager();

		~OnnxApiManager();

		bool
			construct();

		bool
			destruct();

		template<typename Type> std::unordered_map<std::string, std::span<const Type>>
			infer_via_numerics(
				const std::unordered_map<std::string, std::vector<std::vector<Type>>>&
					inputs
			);

		std::unordered_map<std::string, std::vector<std::string>>
			infer_via_strings(
				const std::unordered_map<std::string, std::vector<std::vector<std::string>>>&
					inputs
			);

		template<typename Type> bool
			prepare_numeric_inputs(
				const std::unordered_map<std::string, std::vector<std::vector<Type>>>&
					inputs
			);

		bool
			prepare_string_inputs(
				const std::unordered_map<std::string, std::vector<std::vector<std::string>>>&
					inputs
			);

		template<typename Type> std::unordered_map<std::string, std::span<const Type>>
			collect_numeric_outputs();

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
    };
}
