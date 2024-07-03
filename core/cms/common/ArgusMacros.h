//
// Created by 韩呈杰 on 2024/5/13.
//

#ifndef ARGUSAGENT_COMMON_ARGUS_MACROS_H
#define ARGUSAGENT_COMMON_ARGUS_MACROS_H


#ifdef ENABLE_CLOUD_MONITOR

#   if !defined(WIN32) && defined(ENABLE_COVERAGE)
#       define ENABLE_FILE_CHANNEL
#   endif

#else
#   define ENABLE_FILE_CHANNEL
#endif

// # C++17开始编译器会RVO,不需要再std::move了
#if defined(_MSC_VER)
#   define RETURN_RVALUE(N) return std::move(N)
#elif defined(__GNUC__) && (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__) <= 40902
#   define RETURN_RVALUE(N) return std::move(N)
// #elif defined(__clang__) // Apple\FreeBSD均使用Clang
#else
#   define RETURN_RVALUE(N) return N
#endif

#endif // !ARGUSAGENT_COMMON_ARGUS_MACROS_H
