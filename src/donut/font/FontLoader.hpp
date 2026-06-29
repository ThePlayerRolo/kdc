#ifndef DONUT_FONT_FONT_LOADER_HPP
#define DONUT_FONT_FONT_LOADER_HPP

#include "font/FontKindUtil.hpp"

namespace font {
    class FontLoader {
    public:
        FontLoader(FontKind kind);
        ~FontLoader();
    public:
        /* 0x0 */ FontKind mKind;
    };
}

#endif
