#pragma once

#include "error_manager.hpp"
#include "singleton_manager.hpp"
#include "abstract_configurations.hpp"

QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_TEMPLATE
(
    template <typename AbstractConfigurationsType> class
		AbstractClass
    {
    public:
		QLOGICAE_COR_V1__BASE__HPP__MUTEX_LAYER_1_TEMPLATE();

		AbstractConfigurationsType
			configurations;

		AbstractClass();

		~AbstractClass();

        bool
            construct();

		bool
            destruct();

		virtual bool
            setup(
				const AbstractConfigurationsType&
					new_configurations
			);

		virtual bool
            reset();

		template <typename OutputType = bool> OutputType
			handle_error_outputs(
				const std::string&
					title,
				const std::string&
					message
			);

		template <typename OutputType = bool> OutputType
			handle_error_outputs(
				const std::string&
					message
			);

		template <typename OutputType = bool> OutputType
			handle_error_outputs(
				const std::exception&
					exception
			);

		template <typename OutputType = bool> OutputType
			handle_callback_wrapper(
				const std::function<void()>&
					callback
			);
    };

	template <typename AbstractConfigurationsType>
		AbstractClass<AbstractConfigurationsType>
			::AbstractClass()
    {
		construct();
    }

	template <typename AbstractConfigurationsType>
		AbstractClass<AbstractConfigurationsType>
			::~AbstractClass()
    {
		destruct();
    }

	template <typename AbstractConfigurationsType> bool
		AbstractClass<AbstractConfigurationsType>
			::construct()
	{		
		QLOGICAE_COR_V1__BASE__HPP_CPP__METHOD_TEMPLATE
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_PRE_EXECUTION_GUARD,
			QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
			QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_RETURN_VALUE,

			return
				true;,

			QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_CATCH_CODE
		);
	}

	template <typename AbstractConfigurationsType> bool
		AbstractClass<AbstractConfigurationsType>
			::destruct()
	{
		QLOGICAE_COR_V1__BASE__HPP_CPP__METHOD_TEMPLATE
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_PRE_EXECUTION_GUARD,
			QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
			QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_RETURN_VALUE,

			return
				true;,

			QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_CATCH_CODE
		);
	}

	template <typename AbstractConfigurationsType> bool
		AbstractClass<AbstractConfigurationsType>
			::setup(
				const AbstractConfigurationsType&
					new_configurations
			)
	{
		QLOGICAE_COR_V1__BASE__HPP_CPP__METHOD_TEMPLATE
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_PRE_EXECUTION_GUARD,
			QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
			QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_RETURN_VALUE,

			configurations =
				new_configurations;

			return
				true;,

			QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_CATCH_CODE
		);
	}

	template <typename AbstractConfigurationsType> bool
		AbstractClass<AbstractConfigurationsType>
			::reset()
	{
		QLOGICAE_COR_V1__BASE__HPP_CPP__METHOD_TEMPLATE
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_PRE_EXECUTION_GUARD,
			QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
			QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_RETURN_VALUE,

			configurations =
				{};

			return
				true;,

			QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_CATCH_CODE
		);
	} 
	
	template <typename AbstractConfigurationsType>
	template <typename OutputType> OutputType
		AbstractClass<AbstractConfigurationsType>
			::handle_error_outputs(
				const std::string&
					title,
				const std::string&
					message
			)
	{				
		QLOGICAE_COR_V1__BASE__HPP_CPP__HANDLE_ERROR_OUTPUTS_METHOD_TEMPLATE
		(
			OutputType,
			(title, message)
		);
	}

	template <typename AbstractConfigurationsType>
	template <typename OutputType> OutputType
		AbstractClass<AbstractConfigurationsType>
			::handle_error_outputs(
				const std::string&
					message
			)
	{	
		QLOGICAE_COR_V1__BASE__HPP_CPP__HANDLE_ERROR_OUTPUTS_METHOD_TEMPLATE
		(
			OutputType,
			message
		);
	}

	template <typename AbstractConfigurationsType>
	template <typename OutputType> OutputType
		AbstractClass<AbstractConfigurationsType>
			::handle_error_outputs(
				const std::exception&
					exception
			)
	{
		QLOGICAE_COR_V1__BASE__HPP_CPP__HANDLE_ERROR_OUTPUTS_METHOD_TEMPLATE
		(
			OutputType,
			exception
		);
	} 

	template <typename AbstractConfigurationsType>
	template <typename OutputType> OutputType
		AbstractClass<AbstractConfigurationsType>
			::handle_callback_wrapper(
				const std::function<void()>&
					callback
			)
	{
		QLOGICAE_COR_V1__BASE__HPP_CPP__METHOD_TEMPLATE
		(
			QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_PRE_EXECUTION_GUARD,
			QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1,
			OutputType{},

			callback();

			return
				OutputType{};,

			QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_CATCH_CODE
		);		
	}
);
