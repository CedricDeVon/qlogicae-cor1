#include "pch.hpp"

#include "../includes/temperature_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{       
	TemperatureManager
		::TemperatureManager() :
			AbstractClass<TemperatureManagerConfigurations>()
	{
				
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
			if
			(
				configurations
					.is_runtime_execution_disabled_for_feature_handling() ||				
				(
					configurations
						.is_edge_case_enabled_for_feature_handling() &&
					(
						original_unit == TemperatureUnit::NONE ||
						target_unit == TemperatureUnit::NONE
					)
				)
			)
			{
				return
					0.0;
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
			QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
		)
		{
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
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

