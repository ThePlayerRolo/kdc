//https://github.com/zeldaret/tp/blob/main/libs/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Include/signal.h
#ifndef _MSL_COMMON_SIGNAL_H
#define _MSL_COMMON_SIGNAL_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*__signal_func_ptr)(int);

int raise(int sig);

#ifdef __cplusplus
}
#endif

#endif /* _MSL_COMMON_SIGNAL_H */
