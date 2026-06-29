#ifndef DONUT_FONT_FONTMANAGER_HPP
#define DONUT_FONT_FONTMANAGER_HPP

#include "font/FontKindUtil.hpp"
#include "font/Font.hpp"

namespace font {

class FontManager {
public:
    FontManager();
    ~FontManager();

    Font& font(FontKind kind);
private:
    STRUCT_FILL(0x8C);
};

}

#endif
