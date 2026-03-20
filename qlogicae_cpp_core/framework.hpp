#pragma once

/*
 
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#pragma message("MSVC compiler version: " TOSTRING(_MSC_VER))
#pragma message("MSVC C++ language version (_MSVC_LANG) = " TOSTRING(_MSVC_LANG))

*/

#if !defined(_MSC_VER)
#error "Error - QLogicae::Cor - Compilation via MSVC is required"
#endif

#if _MSVC_LANG < 202002L
#error "Error - QLogicae::Cor - Version C++20 or higher is required"
#endif

#define QLOGICAE_COR_V1_HANDLE_MUTEX_LOCK(method_type, number) \
    boost::unique_lock<boost::mutex> mutex_lock; \
    if (configurations.is_thread_safety_enabled_for_##method_type##_handling()) \
    { \
        mutex_lock = boost::unique_lock<boost::mutex>(method_type##_handling_mutex_##number); \
    } \

#define QLOGICAE_COR_V1_HANDLE_PRE_EXECUTION_WITH_EDGE_CASES(method_type, condition) \
    if (configurations.is_runtime_execution_disabled_for_##method_type##_handling() || \
        (configurations.is_edge_case_enabled_for_##method_type##_handling() && (condition))) \
    { \
        return {}; \
    }

#define QLOGICAE_COR_V1_HANDLE_PRE_EXECUTION_WITHOUT_EDGE_CASES(method_type) \
    if (configurations.is_runtime_execution_disabled_for_##method_type##_handling()) \
    { \
        return {}; \
    }

#define QLOGICAE_COR_V1_HANDLE_ERROR_OUTPUTS(method_type) \
    if (configurations.is_runtime_execution_disabled_for_##method_type##_handling()) \
    { \
        return {}; \
    }

#define QLOGICAE_COR_V1_METHOD_WRAPPER_1(code) \
    try \
	{ \
		code \
	} \
    catch \
    ( \
        const std::exception& \
            exception \
    ) \
    { \
		handle_error_outputs<void>( \
			exception \
		); \
        return {}; \
    }

#define QLOGICAE_COR_V1_METHOD_WRAPPER_2(code) \
    try \
	{ \
		code \
	} \
    catch \
    ( \
        const std::exception& \
            exception \
    ) \
    { \
		handle_error_outputs<void>( \
			exception \
		);
    }


#define QLOGICAE_COR_V1_METHOD_WRAPPER_3(code, type) \
    try \
	{ \
		code \
	} \
    catch \
    ( \
        const std::exception& \
            exception \
    ) \
    { \
        return \
			handle_error_outputs<type>( \
				exception \
			); \
    }

namespace
	QLogicae::Cor::V1
{
	
}
