#include "pch.hpp"

#include "../includes/validation_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
    ValidationManager
		::ValidationManager() :
			QLOGICAE_COR_V1__BASE__HPP_CPP__ABSTRACT_CLASS_NAME<ValidationManagerConfigurations>()
	{
		
	}

	bool
        ValidationManager
			::validate(
				const std::function<bool()>&
					conditional_callback
			)
    {
        try
        {					
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				conditional_callback == nullptr
			);

			return
				conditional_callback();
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
    }

	bool
        ValidationManager
			::validate()
    {
        try
        {				
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				configurations.conditional_callback == nullptr
			);
				
			return
				configurations
					.conditional_callback();
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
    }
}
