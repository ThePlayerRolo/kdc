#include "mintvm/MintSystemCall.hpp"
#include <stdio.h>

namespace mintvm {
    namespace MintSystemCall {
        void panic(const char* pFile, int line, const char* pMsg, ...) {
            va_list list;

            va_start(list, pMsg);
            vprintf(pMsg, list);
            va_end(list);

            printf("[Mint_Panic] file \"%s\" : line %d.\n", pFile, line);
            halt();
        }

        void halt() {
            MintSetting::Instance->m_18();
        }

        void messageHandler(MintMsgKind kind, const char* pMsg, const char* param_3) {
            MintSetting::Instance->mMessageCallback(kind, pMsg, param_3);
            if (kind >= MSG_ERROR) {
                halt();
            }
        }
    }
}
