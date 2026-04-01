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
