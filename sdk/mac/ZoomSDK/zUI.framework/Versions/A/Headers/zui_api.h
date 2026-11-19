#ifndef ZUI_API_H
#define ZUI_API_H

#ifdef _WIN32
#ifdef zUI_EXPORTS
#define ZUI_API __declspec(dllexport)
#else
#define ZUI_API __declspec(dllimport)
#endif
#else
#define ZUI_API __attribute__((visibility("default")))
#endif

#endif
