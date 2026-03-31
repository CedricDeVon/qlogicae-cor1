#pragma once

#define QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_MACROS
#define QLOGICAE_COR_V1__BASE__HPP_CPP__ENUM_CONSTANTS NONE

#define QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME QLogicae::Cor::V1
#define QLOGICAE_COR_V1__BASE__HPP_CPP__COR_SANDBOX_NAMESPACE_NAME QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME::Sandbox
#define QLOGICAE_COR_V1__BASE__HPP_CPP__COR_BENCHMARKS_NAMESPACE_NAME QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME::Benchmarks
#define QLOGICAE_COR_V1__BASE__HPP_CPP__COR_TESTS_NAMESPACE_NAME QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME::Tests

#define QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1 1
#define QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_2 1
#define QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_3 1
#define QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_RETURN_VALUE {}
#define QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_PRE_EXECUTION_GUARD false
#define QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_TRY_CODE QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_MACROS
#define QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_CATCH_CODE QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_MACROS
#define QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_NAMESPACE_CODE QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_MACROS



#define QLOGICAE_COR_V1__BASE__HPP_CPP__NAMESPACE_TEMPLATE(namespace_combination, code) \
	namespace \
		namespace_combination \
	{ \
		code \
	} \

#define QLOGICAE_COR_V1__BASE__HPP__MUTEX_LAYER_TEMPLATE(mutex_layer_number) \
    boost::mutex \
		feature_handling_mutex_##mutex_layer_number; \

#define QLOGICAE_COR_V1__BASE__HPP__MUTEX_LAYER_1_TEMPLATE() \
    QLOGICAE_COR_V1__BASE__HPP__MUTEX_LAYER_TEMPLATE(1); \

#define QLOGICAE_COR_V1__BASE__HPP__MUTEX_LAYER_2_TEMPLATE() \
    QLOGICAE_COR_V1__BASE__HPP__MUTEX_LAYER_TEMPLATE(2); \

#define QLOGICAE_COR_V1__BASE__HPP__MUTEX_LAYER_3_TEMPLATE() \
    QLOGICAE_COR_V1__BASE__HPP__MUTEX_LAYER_TEMPLATE(3); \

#define QLOGICAE_COR_V1__BASE__HPP__ENUM_TEMPLATE(enum_name, constants) \
	enum class \
		enum_name : \
			uint8_t \
	{ \
		constants, \
\
		QLOGICAE_COR_V1__BASE__HPP_CPP__ENUM_CONSTANTS \
	}; \

#define QLOGICAE_COR_V1__BASE__HPP__IMPLEMENTED_CONFIGURATIONS_TEMPLATE(configurations_name, code) \
	struct \
		configurations_name : \
			AbstractConfigurations<configurations_name> \
	{ \
	public: \
		code \
\
		configurations_name(); \
	}; \

#define QLOGICAE_COR_V1__BASE__CPP__IMPLEMENTED_CONFIGURATIONS_TEMPLATE(configurations_name) \
	configurations_name \
		::configurations_name() : \
			AbstractConfigurations<configurations_name>() \
	{ \
\
	} \

#define QLOGICAE_COR_V1__BASE__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE(edge_case_conditions, return_value) \
    if ( \
		configurations \
			.is_runtime_execution_disabled_for_feature_handling() || \
        ( \
			configurations \
				.is_edge_case_enabled_for_feature_handling() && \
			(edge_case_conditions) \
		) \
	) \
    { \
        return \
			return_value; \
    } \

#define QLOGICAE_COR_V1__BASE__HPP_CPP__THREAD_SAFETY_GUARD_TEMPLATE(mutex_layer_number) \
    boost::unique_lock<boost::mutex> \
		mutex_lock; \
\
    if ( \
		configurations \
			.is_thread_safety_enabled_for_feature_handling() \
	) \
    { \
        mutex_lock = \
			boost::unique_lock<boost::mutex>( \
				feature_handling_mutex_##mutex_layer_number \
			); \
    } \

#define QLOGICAE_COR_V1__BASE__HPP_CPP__CATCH_CODE_TEMPLATE(return_value) \
    handle_error_outputs<void>( \
		exception \
	); \
\
	return \
		return_value; \

#define QLOGICAE_COR_V1__BASE__HPP_CPP__METHOD_TEMPLATE(edge_case_conditions, mutex_layer_number, return_value, try_code, catch_code) \
	try \
	{ \
		QLOGICAE_COR_V1__BASE__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE \
		( \
			edge_case_conditions, \
			return_value \
		); \
		QLOGICAE_COR_V1__BASE__HPP_CPP__THREAD_SAFETY_GUARD_TEMPLATE \
		( \
			mutex_layer_number \
		); \
\
		try_code \
	} \
	catch \
	( \
		const std::exception& \
			exception \
	) \
	{ \
		catch_code \
\
		QLOGICAE_COR_V1__BASE__HPP_CPP__CATCH_CODE_TEMPLATE \
		( \
			return_value \
		); \
	} \

#define QLOGICAE_COR_V1__BASE__HPP_CPP__HANDLE_ERROR_OUTPUTS_METHOD_TEMPLATE(return_type, code) \
	QLOGICAE_COR_V1__BASE__HPP_CPP__PRE_EXECUTION_GUARD_TEMPLATE \
	( \
		QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_PRE_EXECUTION_GUARD, \
		return_type {} \
	); \
\
	return \
		SingletonManager \
			::get_singleton<ErrorManager>() \
				.handle_error_outputs<return_type>( \
					code \
			); \

#define QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_TEMPLATE(code) \
	QLOGICAE_COR_V1__BASE__HPP_CPP__NAMESPACE_TEMPLATE \
	( \
		QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME, \
\
		code \
	);




/*





*/
