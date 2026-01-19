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
						method_handling_layer_mutex_1
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
						method_handling_layer_mutex_1
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
}

/*

bool
		TemperatureManager::cache_boolean_1 =
			false;

	TemperatureManager&
		TemperatureManager::singleton =
			TemperatureManager::get_singleton<TemperatureManager>();

	TemperatureManager::TemperatureManager()
	{
		try
		{
			_handle_construct();
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	TemperatureManager::~TemperatureManager()
	{
		try
		{
			_handle_destruct();
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	bool
		TemperatureManager::construct()
	{
		_handle_construct();

		return
			cache_boolean_1;
	}

	bool
		TemperatureManager::destruct()
	{
		_handle_destruct();

		return
			cache_boolean_1;
	}

	bool
		TemperatureManager::setup(
			const TemperatureManagerConfigurations&
				new_configurations
		)
	{
		TemperatureManagerConfigurations::cache =
			new_configurations;

		_handle_setup();

		return
			cache_boolean_1;
	}

	bool
		TemperatureManager::setup()
	{
		TemperatureManagerConfigurations::cache =
			{};

		_handle_setup();

		return
			cache_boolean_1;
	}

	bool
		TemperatureManager::reset()
	{
		_handle_reset();

		return
			cache_boolean_1;
	}

	double
		TemperatureManager::calculate(
			const double&
				value,
			const TemperatureUnitType&
				from_unit_type,
			const TemperatureUnitType&
				to_unit_type
		)
	{
		TemperatureManagerConfigurations::cache_value =
			value;

		TemperatureManagerConfigurations::cache_from_unit_type =
			from_unit_type;

		TemperatureManagerConfigurations::cache_to_unit_type =
			to_unit_type;

		_handle_calculate();

		return
			TemperatureManagerConfigurations::cache_value;
	}

	double
		TemperatureManager::calculate(
			const double&
				value
		)
	{
		TemperatureManagerConfigurations::cache_value =
			value;

		TemperatureManagerConfigurations::cache_from_unit_type =
			TemperatureManagerConfigurations::default_from_unit_type;

		TemperatureManagerConfigurations::cache_to_unit_type =
			TemperatureManagerConfigurations::default_to_unit_type;

		_handle_calculate();

		return
			TemperatureManagerConfigurations::cache_value;
	}

	double
		TemperatureManager::calculate(
			const TemperatureManagerConfigurations&
				new_configurations
		)
	{
		TemperatureManagerConfigurations::cache_value =
			TemperatureManagerConfigurations::default_value;

		TemperatureManagerConfigurations::cache_from_unit_type =
			TemperatureManagerConfigurations::default_from_unit_type;

		TemperatureManagerConfigurations::cache_to_unit_type =
			TemperatureManagerConfigurations::default_to_unit_type;

		_handle_calculate();

		return
			TemperatureManagerConfigurations::cache_value;
	}

	void
		TemperatureManager::_handle_construct()
	{
		try
		{
			cache_boolean_1 =
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		TemperatureManager::_handle_destruct()
	{
		try
		{
			cache_boolean_1 =
				true;
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		TemperatureManager::_handle_setup()
	{
		try
		{
			TemperatureManagerUtilities::singleton
				._handle_setup();
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		TemperatureManager::_handle_reset()
	{
		try
		{
			TemperatureManagerUtilities::singleton
				._handle_reset();
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

	void
		TemperatureManager::_handle_calculate()
	{
		try
		{
			if (!TemperatureManagerConfigurations::cache_is_enabled)
			{
				return;
			}

			switch (TemperatureManagerConfigurations::cache_from_unit_type)
			{
				case TemperatureUnitType::CELSIUS:
				{
					break;
				}
				case TemperatureUnitType::FAHRENHEIT:
				{
					TemperatureManagerConfigurations::cache_value =
						(TemperatureManagerConfigurations::cache_value - 32.0) * 5.0 / 9.0;

					break;
				}
				case TemperatureUnitType::KELVIN:
				{
					TemperatureManagerConfigurations::cache_value =
						TemperatureManagerConfigurations::cache_value - 273.15;

					break;
				}
				default:
				{
					break;
				}
			}

			switch (TemperatureManagerConfigurations::cache_to_unit_type)
			{
				case TemperatureUnitType::CELSIUS:
				{
					break;
				}
				case TemperatureUnitType::FAHRENHEIT:
				{
					TemperatureManagerConfigurations::cache_value =
						(TemperatureManagerConfigurations::cache_value * 9.0 / 5.0) + 32.0;

					break;
				}
				case TemperatureUnitType::KELVIN:
				{
					TemperatureManagerConfigurations::cache_value =
						TemperatureManagerConfigurations::cache_value + 273.15;

					break;
				}
				default:
				{
					break;
				}
			}
		}
		catch
		(
			const std::exception&
				exception
		)
		{
			ErrorManager::cache_error_log =
				exception.what();

			ErrorManager::singleton
				._handle();
		}
	}

*/ 
