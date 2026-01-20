#include "pch.hpp"

#include "../includes/temperature_manager.hpp"

namespace
	QLogicaeCppCore
{       
    TemperatureManager&
        TemperatureManager
			::singleton =
				SingletonManager
					::get_singleton<TemperatureManager>();



	TemperatureManager
		::TemperatureManager() :
			AbstractClass<TemperatureManagerConfigurations>()
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

	TemperatureManager
		::~TemperatureManager()
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
        TemperatureManager
			::construct()
    {
        try
        {			
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
        TemperatureManager
			::destruct()
    {
        try
        {		
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

	double
		TemperatureManager
			::convert_unit(
				const double&
					value,
				const TemperatureUnit&
					original_unit,
				const TemperatureUnit&
					target_unit
			)
	{
		try
		{		
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

			double
				result = value;

			switch (original_unit)
			{
				case TemperatureUnit::CELSIUS:
				{
					break;
				}
				case TemperatureUnit::FAHRENHEIT:
				{
					result =
						(result - 32.0) * 5.0 / 9.0;

					break;
				}
				case TemperatureUnit::KELVIN:
				{
					result =
						result - 273.15;

					break;
				}
				default:
				{
					break;
				}
			}

			switch (target_unit)
			{
				case TemperatureUnit::CELSIUS:
				{
					break;
				}
				case TemperatureUnit::FAHRENHEIT:
				{
					result =
						(result * 9.0 / 5.0) + 32.0;

					break;
				}
				case TemperatureUnit::KELVIN:
				{
					result =
						result + 273.15;

					break;
				}
				default:
				{
					break;
				}
			}

			return
				result;
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

	double
		TemperatureManager
			::convert_unit(
				const double&
					value
			)
	{
		return
			convert_unit(
				value,
				configurations
					.original_unit,
				configurations
					.target_unit
			);
	}
}
