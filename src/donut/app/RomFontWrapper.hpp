#ifndef DONUT_APP_ROMFONTWRAPPER_HPP
#define DONUT_APP_ROMFONTWRAPPER_HPP

#include "mem/DataBlock.hpp"
#include <nw4r/ut.h>

namespace app {
    class RomFontWrapper {
    public:
        RomFontWrapper();
        ~RomFontWrapper();

        nw4r::ut::RomFont& font();
    private:
        /* 0x0 */ mem::DataBlock mBlock;
        /* 0xC */ nw4r::ut::RomFont mFont;
    };
}

#endif
