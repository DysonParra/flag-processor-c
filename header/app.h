#ifndef APP_H_

#define APP_H_

/* Includes for the header file */

#ifdef __cplusplus
#define LANGUAGE extern "C"
#elif defined __GNUC__
#define LANGUAGE extern
#endif

#ifdef APP_STATIC_
#define DLLIMPORT
#elif defined BUILDING
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

#define CALLING __cdecl
//#define CALLING __stdcall

/* Macros and definitions for the source file. */
#ifdef APP_DEFINITIONS_
#define elif else if
#define null NULL
#define for_each_array_idx(index, item, array) \
    int index = 0;                             \
    while ((item = array[index]) && item != 0 && ++index)
#define for_each_array(item, array) for_each_array_idx(index, item, array)
#endif

#if !defined BUILDING
#undef LANGUAGE
#undef DLLIMPORT
#undef CALLING
#endif

#endif
