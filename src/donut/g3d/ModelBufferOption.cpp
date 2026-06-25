#pragma peephole off
#include "g3d/ModelBufferOption.hpp"

namespace g3d {
    ModelBufferOption::ModelBufferOption()
    : _0(false)
    , _1(false)
    , _2(false)
    , _3(false)
    , _4(false)
    , _5(false)
    , _6(false)
    , _7(false)
    , _8(false)
    , _9(false)
    , _A(false)
    , _B(false)
    , _C(false)
    , _D(false)
    , _E(false)
    , _F(false)
    { }

    void ModelBufferOption::addAnimMatColor() {
        _3 = _8 = true;
    }

    void ModelBufferOption::addAnimTexPattern() {
        _1 = _0 = true;
    }

    void ModelBufferOption::addAnimTexSRT() {
        _2 = true;
    }

    void ModelBufferOption::addAnimVisible() {
        _6 = true;
    }

    u32 ModelBufferOption::value() const {
        u32 value = _0;
        value |= (_1) & 2;
        value |= (-_2) & 4;
        value |= (-_3) & 8;
        value |= (-_4) & 16;
        value |= (-_5) & 32;
        value |= (-_6) & 64;
        value |= (-_7) & 128;
        value |= (-_8) & 256;
        value |= (-_9) & 512;
        value |= (-_A) & 1024;
        value |= (-_B) & 2048;
        value |= (-_C) & 4096;
        value |= (-_D) & 8192;
        value |= (-_E) & 16384;
        value |= (-_F) & 16777216;

        return value;
    }
}
