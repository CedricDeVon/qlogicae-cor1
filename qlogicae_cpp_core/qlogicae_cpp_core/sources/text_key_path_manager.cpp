#include "pch.hpp"

#include "../includes/text_key_path_manager.hpp"

namespace
	QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{        	
	TextKeyPathManager
		::TextKeyPathManager() :
			AbstractClass<TextKeyPathManagerConfigurations>()
    {
        
    }

	std::vector<std::string>
		TextKeyPathManager
			::convert_key_path(
				const std::string&
					key_path,
				const std::string&
					delimeter
			)
	{
		try
        {					
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				key_path.empty()
			);

			return
				(delimeter != "") ?
					absl::StrSplit(
						key_path,
						delimeter
					) :
					std::vector<std::string> { key_path };
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {				
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
	}

	std::string
		TextKeyPathManager
			::convert_key_path(
				const std::vector<std::string>&
					key_path,
				const std::string&
					delimeter
			)
	{
		try
        {					
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE
			(
				QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
				!key_path.size() ||
				delimeter.empty()
			);

			return
				absl::StrJoin(
					key_path,
					delimeter
				);
        }
        catch
        (
            QLOGICAE_COR_V1__BASE__HPP_CPP__TRY_CATCH_EXCEPTION_PARAMETER
        )
        {				
			QLOGICAE_COR_V1__IMPLICIT__HPP_CPP__CATCH_CODE_TEMPLATE();
        }
	}

	std::vector<std::string>
		TextKeyPathManager
			::convert_key_path(
				const std::string&
					key_path
			)
	{
		return
			convert_key_path(
				key_path,
				configurations
					.delimeter
			);
	}

	std::string
		TextKeyPathManager
			::convert_key_path(
				const std::vector<std::string>&
					key_path
			)
	{
		return
			convert_key_path(
				key_path,
				configurations
					.delimeter
			);
	}
}
