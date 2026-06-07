#pragma once

/*
#if QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_CONDITIONS_ENABLED_TEMPLATE( \
	AccountSessionsManager \
)
*/

namespace
	QLOGICAE_COR1__BASE__HPP_CPP__COR_NAMESPACE_NAME
{
	template <typename EnumType> struct
		AbstractBatchOperationConfigurations
	{
	public:						
		std::string
			file_path = 
				"";

		std::any
			inputs =
				{};

		bool
			is_asynchronous =
				false;

		bool
			is_error_ignored =
				false;

		EnumType
			operation_type =
				EnumType
					::NONE;
	};
}

// #endif
