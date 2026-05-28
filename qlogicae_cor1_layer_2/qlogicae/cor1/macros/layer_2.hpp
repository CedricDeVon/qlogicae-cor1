#pragma once

#include "qlogicae/cor1/macros/layer_1.hpp"

#include "qlogicae/cor1/includes/abstract_enum.hpp"
#include "qlogicae/cor1/includes/error_manager.hpp"
#include "qlogicae/cor1/includes/abstract_class.hpp"
#include "qlogicae/cor1/includes/singleton_manager.hpp"



#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			AbslVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__AbslVcpkgImports__IS_COMPILATION_ENABLED 1

	#include <absl/time/time.h> 
	#include <absl/time/clock.h> 
	#include <absl/strings/ascii.h> 
	#include <absl/strings/str_cat.h> 
	#include <absl/strings/str_join.h> 
	#include <absl/strings/str_split.h> 
	#include <absl/strings/str_replace.h> 

#else
#endif



#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			BoostVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__BoostVcpkgImports__IS_COMPILATION_ENABLED 1

	#include <boost/thread/mutex.hpp> 
	#include <boost/thread/locks.hpp> 
	#include <boost/thread/shared_mutex.hpp> 
	#include <boost/thread/recursive_mutex.hpp> 

#else
#endif



#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			CurlVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__CurlVcpkgImports__IS_COMPILATION_ENABLED 1

	#include <curl/curl.h> 

#else
#endif



#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			FastIoVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__FastIoVcpkgImports__IS_COMPILATION_ENABLED 1

	#include <fast_io_device.h> 

#else
#endif



#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			FollyVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__FollyVcpkgImports__IS_COMPILATION_ENABLED 1

	#ifdef _M_X64
		#include <folly/init/Init.h> 
		#include <folly/synchronization/MicroSpinLock.h> 

	#endif

#else
#endif



#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			SodiumVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__SodiumVcpkgImports__IS_COMPILATION_ENABLED 1

	#ifndef SALT_LEN
		#define SALT_LEN crypto_pwhash_SALTBYTES

	#endif

	#include <sodium.h> 

#else
#endif



#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			Pcre2VcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__Pcre2VcpkgImports__IS_COMPILATION_ENABLED 1

	#ifndef PCRE2_CODE_UNIT_WIDTH
		#define PCRE2_CODE_UNIT_WIDTH 8
	#endif

	#include <pcre2.h> 

#else
#endif



#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			EfswVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__EfswVcpkgImports__IS_COMPILATION_ENABLED 1

	#ifndef ORT_DISABLE_SCHEMA_VALIDATION
	#define ORT_DISABLE_SCHEMA_VALIDATION 1
	#endif

	#include <efsw/efsw.hpp>

#else
#endif



#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			CppCodecVcpkgImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__CppCodecVcpkgImports__IS_COMPILATION_ENABLED 1

	#include <cppcodec/base32_rfc4648.hpp> 

#else
#endif



#if QLOGICAE_COR1__BASE__HPP_CPP__COMPILATION_CONDITIONS_TEMPLATE( \
		QLOGICAE_COR1__BASE__HPP_CPP__IS_COMPILATION_ENABLED_TEMPLATE( \
			StdImports \
		) \
	)
	#define QLOGICAE_COR1__BASE__HPP_CPP__StdImports__IS_COMPILATION_ENABLED 1

	#include <unordered_set>
	#include <unordered_map>
	#include <random>
	#include <iostream>
	#include <shlobj.h>

#else
#endif
