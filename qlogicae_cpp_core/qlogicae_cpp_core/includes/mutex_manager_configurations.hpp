#pragma once

namespace
	QLogicaeCppCore
{   
    struct
		MutexManagerConfigurations
    {
        std::string
            name =
                default_configurations
					.name;

        bool
            is_enabled =
                default_configurations
					.is_enabled;

		bool
			is_thread_safety_enabled =
				default_configurations
					.is_thread_safety_enabled;



		static MutexManagerConfigurations
			initial_configurations;

		static MutexManagerConfigurations
			default_configurations;
    };
}
