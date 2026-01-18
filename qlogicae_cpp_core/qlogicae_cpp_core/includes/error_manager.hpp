#pragma once

#include "error_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{    
    class
		ErrorManager
    {
    public:   
		boost::mutex
			method_handling_layer_mutex_1;

		ErrorManagerConfigurations
			configurations;

		static ErrorManager&
			singleton;

		ErrorManager();

		~ErrorManager();

		bool
			construct();

		bool
			destruct();

		bool
			setup(
				const ErrorManagerConfigurations&
					new_configurations =
						{}
			);

		bool
			reset();

		bool
			handle_error_outputs(
				const std::string&
					title,
				const std::string&
					message
			);

		bool
			handle_error_outputs(
				const std::string&
					message
			);

		bool
			handle_error_outputs(
				const std::exception&
					exception
			);

		bool
			handle_error_output_conditions(
				const std::string&
					error_log
			);

		std::string
			transform_to_error_log(
				const std::string&
					title,
				const std::string&
					message
			);

		std::string
			transform_to_error_log(
				const std::string&
					message
			);

		std::string
			transform_to_error_log(
				const std::exception&
					exception
			);

		bool
			handle_error_outputs_synchronously(
				const std::string&
					error_log
			);

		bool
			handle_error_outputs_asynchronously(
				const std::string&
					error_log
			);

		static ErrorManager&
			get_this_singleton();
    };        
}
