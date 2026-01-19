#include "pch.hpp"

#include "../includes/validation_manager_configurations.hpp"

namespace
	QLogicaeCppCore
{
	ValidationManagerConfigurations
		ValidationManagerConfigurations
			::initial_configurations =
				[]()
				{
					ValidationManagerConfigurations
						configurations;

					configurations
						.is_method_execution_enabled =
							true;
					
					configurations
						.is_error_handling_enabled =
							true;

					configurations
						.is_thread_safety_override_enabled =
							false;

					configurations
						.is_method_execution_thread_safety_enabled =
							true;

					configurations
						.is_error_handling_thread_safety_enabled =
							true;

					return
						configurations;
				}();

	ValidationManagerConfigurations
		ValidationManagerConfigurations
			::default_configurations =
				ValidationManagerConfigurations
					::initial_configurations;
}


/*


std::size_t
minimum_length =
8;

std::size_t
maximum_length =
128;

bool
require_alpha_numerics =
true;

bool
require_unique_characters =
false;

bool
require_special_characters =
true;

bool
require_uppercase_characters =
true;

bool
require_lowercase_characters =
true;


*/ 
