#ifndef DONUT_MINTVM_MINT_SETTING_HPP
#define DONUT_MINTVM_MINT_SETTING_HPP

#include "mintvm/MintAllocator.hpp"
#include "mintvm/ExplicitSingleton.hpp"

namespace mintvm {
    enum MintMsgKind {
        MSG_WARNING,
        MSG_ERROR,
        MSG_FATAL,
    };

    class MintSetting : public ExplicitSingleton<MintSetting> {
    public:
        DECL_MINTVM_EXPLICIT_SINGLETON(MintSetting)
        typedef void(*Unk18Callback)();
        typedef void (*MessageCallback)(MintMsgKind, const char*, const char*);

        MintSetting();
    public :
        /* 0x00 */ MintAllocator _0;
        /* 0x0C */ MintAllocator _C;
        /* 0x18 */ Unk18Callback _18;
        /* 0x1C */ s32 _1C;
        /* 0x20 */ MessageCallback mMessageCallback;
    };
}

#endif
