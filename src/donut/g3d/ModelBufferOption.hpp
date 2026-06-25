#ifndef DONUT_G3D_MODEL_BUFFER_OPTION_HPP
#define DONUT_G3D_MODEL_BUFFER_OPTION_HPP

#include <types.h>

namespace g3d {
    class ModelBufferOption {
    public:
        ModelBufferOption();

        void addAnimMatColor();
        void addAnimTexPattern();
        void addAnimTexSRT();
        void addAnimVisible();
        u32 value() const;

    public:
        /* 0x0 */ bool _0;
        /* 0x1 */ bool _1;
        /* 0x2 */ bool _2;
        /* 0x3 */ bool _3;
        /* 0x4 */ bool _4;
        /* 0x5 */ bool _5;
        /* 0x6 */ bool _6;
        /* 0x7 */ bool _7;
        /* 0x8 */ bool _8;
        /* 0x9 */ bool _9;
        /* 0xA */ bool _A;
        /* 0xB */ bool _B;
        /* 0xC */ bool _C;
        /* 0xD */ bool _D;
        /* 0xE */ bool _E;
        /* 0xF */ bool _F;
    };
}

#endif
