#ifndef DONUT_MINTVM_MINT_SYSTEM_CALL_HPP
#define DONUT_MINTVM_MINT_SYSTEM_CALL_HPP

#include "mintvm/MintSetting.hpp"

namespace mintvm {
    namespace MintSystemCall {
        void panic(const char* pFile, int line, const char* pMsg, ...);
        void halt() DONT_INLINE;
        void messageHandler(MintMsgKind, const char*, const char*);
    }
}


#endif
