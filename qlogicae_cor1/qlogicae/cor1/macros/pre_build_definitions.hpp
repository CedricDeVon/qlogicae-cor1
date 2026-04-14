#pragma once

// Visual Studio 2026

#ifndef NOMINMAX
#define NOMINMAX
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef HASH_LEN
#define HASH_LEN 32
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0A00
#endif

// Vcpkg

#ifndef PCRE2_CODE_UNIT_WIDTH
#define PCRE2_CODE_UNIT_WIDTH 8
#endif

#ifndef ORT_DISABLE_SCHEMA_VALIDATION
#define ORT_DISABLE_SCHEMA_VALIDATION 1
#endif

#ifndef SALT_LEN
#define SALT_LEN crypto_pwhash_SALTBYTES
#endif

// QLogicae


