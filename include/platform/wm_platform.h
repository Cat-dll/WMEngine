#ifndef _WM_PLATFORM_H_
#define _WM_PLATFORM_H_

#include <wm_engine.h>

#define WIN32 _WIN32

#ifdef WIN32
    #ifdef _MSC_VER 
        #include <Windows.h>
    #else
        #include <windows.h>
    #endif

    #ifdef WM_SHARED_LIB_USE
        #define WMAPI __declspecs(dllimport)
    #else
        #define WMAPI __declspecs(dllexport)
    #endif
#else
    // NOTE(catdll): Other platform export/import without symbol
    #define WSAPI
#endif




typedef struct wm_platform_t WmPlatform;
typedef struct wm_platform_data_t WmPlatformData;

// TODO: Remplace by a stable error handling process
#define RAISE_ERROR exit(EXIT_FAILURE);

#define private static
#define internal static
#define global static
#define local_persist static

#endif