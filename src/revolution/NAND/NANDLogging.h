#ifndef RVL_SDK_NAND_LOGGING_H
#define RVL_SDK_NAND_LOGGING_H
#include <types.h>

#include <revolution/NAND/nand.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef void (*NANDLoggingCallback)(BOOL, s32);
BOOL NANDLoggingAddMessageAsync(NANDLoggingCallback cb, s32 errorCode, const char* fmt, ...);

#ifdef __cplusplus
}
#endif
#endif
