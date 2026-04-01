#pragma once

#define QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_MACROS
#define QLOGICAE_COR_V1__BASE__HPP_CPP__ENUM_CONSTANTS NONE

#define QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME QLogicae::Cor::V1
#define QLOGICAE_COR_V1__BASE__HPP_CPP__COR_SANDBOX_NAMESPACE_NAME QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME::Sandbox
#define QLOGICAE_COR_V1__BASE__HPP_CPP__COR_BENCHMARKS_NAMESPACE_NAME QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME::Benchmarks
#define QLOGICAE_COR_V1__BASE__HPP_CPP__COR_TESTS_NAMESPACE_NAME QLOGICAE_COR_V1__BASE__HPP_CPP__COR_NAMESPACE_NAME::Tests

#define QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_1 1
#define QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_2 2
#define QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_3 3
#define QLOGICAE_COR_V1__BASE__HPP_CPP__MUTEX_LAYER_4 4
#define QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_RETURN_VALUE {}
#define QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_PRE_EXECUTION_GUARD false
#define QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_TRY_CODE QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_MACROS
#define QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_CATCH_CODE QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_MACROS
#define QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_NAMESPACE_CODE QLOGICAE_COR_V1__BASE__HPP_CPP__EMPTY_MACROS



#define QLOGICAE_COR_V1__BASE__HPP__MUTEX_LAYER_TEMPLATE(mutex_layer_number) \
	feature_handling_mutex_##mutex_layer_number; \

#define QLOGICAE_COR_V1__INSTANCE__HPP__MUTEX_LAYER_TEMPLATE(mutex_layer_number) \
    boost::mutex \
		QLOGICAE_COR_V1__BASE__HPP__MUTEX_LAYER_TEMPLATE(mutex_layer_number); \

#define QLOGICAE_COR_V1__STATIC__HPP__MUTEX_LAYER_TEMPLATE(mutex_layer_number) \
    static boost::mutex \
		QLOGICAE_COR_V1__BASE__HPP__MUTEX_LAYER_TEMPLATE(mutex_layer_number); \

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

#define QLOGICAE_COR_V1__BASE__HPP_CPP__HANDLE_ERROR_OUTPUTS_METHOD_TEMPLATE(return_type, ...) \
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
					__VA_ARGS__ \
			); \

#define QLOGICAE_COR_V1__BASE__HPP_CPP__FIRST_ENUM_TO_STRING_STATEMENT_TEMPLATE(enum_name, enum_constant) \
	case (enum_name::enum_constant): return #enum_constant; \

#define QLOGICAE_COR_V1__BASE__HPP_CPP__MIDDLE_ENUM_TO_STRING_STATEMENT_TEMPLATE(enum_name, enum_constant) \
	case (enum_name::enum_constant): return #enum_constant; \

#define QLOGICAE_COR_V1__BASE__HPP_CPP__FINAL_ENUM_TO_STRING_STATEMENT_TEMPLATE(enum_name, enum_constant) \
	case (enum_name::enum_constant): return #enum_constant; \
	default: return #enum_constant; \

#define QLOGICAE_COR_V1__BASE__HPP_CPP__FIRST_STRING_TO_ENUM_STATEMENT_TEMPLATE(enum_name, enum_constant) \
	if (value == #enum_constant) return enum_name::enum_constant; \

#define QLOGICAE_COR_V1__BASE__HPP_CPP__MIDDLE_STRING_TO_ENUM_STATEMENT_TEMPLATE(enum_name, enum_constant) \
	else if (value == #enum_constant) return enum_name::enum_constant; \

#define QLOGICAE_COR_V1__BASE__HPP_CPP__FINAL_STRING_TO_ENUM_STATEMENT_TEMPLATE(enum_name, enum_constant) \
	else return enum_name::enum_constant; \


#define QLOGICAE_COR_V1__BASE__HPP_CPP__ENUM_TO_STRING_SWITCH_CASE_STATEMENT_TEMPLATE(enum_constants) \
	switch (value) \
	{ \
		enum_constants \
		( \
			QLOGICAE_COR_V1__BASE__HPP_CPP__FIRST_ENUM_TO_STRING_STATEMENT_TEMPLATE, \
			QLOGICAE_COR_V1__BASE__HPP_CPP__MIDDLE_ENUM_TO_STRING_STATEMENT_TEMPLATE, \
			QLOGICAE_COR_V1__BASE__HPP_CPP__FINAL_ENUM_TO_STRING_STATEMENT_TEMPLATE \
		) \
	} \

#define QLOGICAE_COR_V1__BASE__HPP_CPP__STRING_TO_ENUM_SWITCH_CASE_STATEMENT_TEMPLATE(enum_constants) \
	enum_constants \
	( \
		QLOGICAE_COR_V1__BASE__HPP_CPP__FIRST_STRING_TO_ENUM_STATEMENT_TEMPLATE, \
		QLOGICAE_COR_V1__BASE__HPP_CPP__MIDDLE_STRING_TO_ENUM_STATEMENT_TEMPLATE, \
		QLOGICAE_COR_V1__BASE__HPP_CPP__FINAL_STRING_TO_ENUM_STATEMENT_TEMPLATE \
	) \	

/*

#define QLOGICAE_COR_V1__BASE__HPP_CPP__EMAIL_BODY_ENUM_CONSTANTS(first_statement, middle_statement, final_statement) \
	first_statement(EmailBody, HTML) \
	middle_statement(EmailBody, PLAIN) \
	final_statement(EmailBody, NONE) \


#define QLOGICAE_COR_V1__BASE__HPP__ENUM_TEMPLATE(enum_name, ...) \
	enum class \
		enum_name : \
			uint8_t \
	{ \
		__VA_ARGS__, \
\
		QLOGICAE_COR_V1__BASE__HPP_CPP__ENUM_CONSTANTS \
	}; \

#define QLOGICAE_COR_V1__BASE__HPP__IMPLEMENTED_CONFIGURATIONS_TEMPLATE(configurations_name, ...) \
	struct \
		configurations_name : \
			AbstractConfigurations<configurations_name> \
	{ \
	public: \
		__VA_ARGS__ \
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


*/
 