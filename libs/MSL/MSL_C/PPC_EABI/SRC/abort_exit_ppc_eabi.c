#include "abort_exit_ppc_eabi.h"
#include <signal.h>
#include <revolution/OS.h>

int __stdio_exit = 0;
BOOL __aborting = 0;

void abort() {
    raise(1);
    __aborting = TRUE;
    exit(1);
}
