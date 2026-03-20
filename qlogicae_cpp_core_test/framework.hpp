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
	
#define QLOGICAE_COR_HANDLE_MUTEX_LOCK(method_type, number) \
	boost::unique_lock<boost::mutex> mutex_lock; \
	if (configurations.is_thread_safety_enabled_for_##method_type##_handling()) \
	{ \
		mutex_lock = boost::unique_lock<boost::mutex>(method_type##_handling_mutex_##number); \
	} \

#define QLOGICAE_COR_HANDLE_PRE_EXECUTION_WITH_EDGE_CASES(method_type, condition) \
	if (configurations.is_runtime_execution_disabled_for_##method_type##_handling() || \
		(configurations.is_edge_case_enabled_for_##method_type##_handling() && (condition))) \
	{ \
		return {}; \
	}

#define QLOGICAE_COR_HANDLE_PRE_EXECUTION_WITHOUT_EDGE_CASES(method_type) \
	if (configurations.is_runtime_execution_disabled_for_##method_type##_handling()) \
	{ \
		return {}; \
	}

namespace
	QLogicae::Cor::V1::Tests
{

}
