#include "pch.hpp"

#include "../includes/temperature_unit_enum_manager.hpp"

namespace
	QLogicaeCppCore
{        
	TemperatureUnitEnumManager&
		TemperatureUnitEnumManager
			::singleton = 
				SingletonManager
					::get_singleton<TemperatureUnitEnumManager>();	


	
	TemperatureUnitEnumManager
		::TemperatureUnitEnumManager() :
			AbstractClass<TemperatureUnitEnumManagerConfigurations>()
    {
        try
        {
            construct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);
        }
    }

    TemperatureUnitEnumManager
		::~TemperatureUnitEnumManager()
    {
        try
        {
            destruct();
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			handle_error_outputs(
				exception
			);
        }
    }

    bool
        TemperatureUnitEnumManager
			::construct()
    {
        try
        {			
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						utility_handling_mutex_1
					);
			}			

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
    }

    bool
        TemperatureUnitEnumManager
			::destruct()
    {
        try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_utility_handling()
			)
			{
				return
					false;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_utility_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						utility_handling_mutex_1
					);
			}			

			return
				true;
        }
        catch
        (
            const std::exception&
                exception
        )
        {
			return
				handle_error_outputs(
					exception
				);
        }
    }

	std::string
		TemperatureUnitEnumManager
			::convert_enum_to_string(
				const TemperatureUnit&
					value
			)
	{
		try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					"NONE";
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			switch (value)
			{
				case (TemperatureUnit::CELSIUS):
				{
					return
						"CELSIUS";
				}
				case (TemperatureUnit::FAHRENHEIT):
				{
					return
						"FAHRENHEIT";
				}
				case (TemperatureUnit::KELVIN):
				{
					return
						"KELVIN";
				}
				case (TemperatureUnit::NONE):
				{
					return
						"NONE";
				}				
				default:
				{
					return
						"NONE";
				}
			}
        }
        catch
        (
            const std::exception&
                exception
        )
        {	
			handle_error_outputs(
				exception
			);

			return
				"NONE";
        }
	}

	std::string
		TemperatureUnitEnumManager
			::convert_enum_to_string()
	{
		return
			convert_enum_to_string(
				configurations
					.type
			);
	}

	TemperatureUnit
		TemperatureUnitEnumManager
			::convert_string_to_enum(
				const std::string&
					value
			)
	{
		try
        {		
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling()
			)
			{
				return
					TemperatureUnit
						::NONE;
			}

			boost::unique_lock<boost::mutex>
				mutex_lock;
			if (configurations.is_thread_safety_enabled_for_feature_handling())
			{
				mutex_lock =
					boost::unique_lock<boost::mutex>
					(
						feature_handling_mutex_1
					);
			}			

			if
			(
				value == "CELSIUS"
			)
			{
				return
					TemperatureUnit
						::CELSIUS;
			}
			else if
			(
				value == "FAHRENHEIT"
			)
			{
				return
					TemperatureUnit
						::FAHRENHEIT;
			}
			else if
			(
				value == "KELVIN"
			)
			{
				return
					TemperatureUnit
						::KELVIN;
			}			
			else if
			(
				value == "NONE"
			)
			{
				return
					TemperatureUnit
						::NONE;
			}
			else
			{
				return
					TemperatureUnit
						::NONE;
			}
        }
        catch
        (
            const std::exception&
                exception
        )
        {		
			handle_error_outputs(
				exception
			);
			
			return	
				TemperatureUnit
					::NONE;
        }
	}

	TemperatureUnit
		TemperatureUnitEnumManager
			::convert_string_to_enum()
	{
		return
			convert_string_to_enum(
				convert_enum_to_string(
					configurations
						.type
				)
			);
	}
}
