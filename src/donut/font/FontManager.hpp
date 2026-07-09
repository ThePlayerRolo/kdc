#ifndef DONUT_FONT_FONTMANAGER_HPP
#define DONUT_FONT_FONTMANAGER_HPP

#include "font/FontKindUtil.hpp"
#include "font/Font.hpp"
#include "mem/AutoHeapExp.hpp"
#include "mem/ExplicitAutoDeleteArray.hpp"

namespace font {

class FontManager : public mem::AutoHeapExp {
public:
    FontManager();
    ~FontManager();

    void setup();
    bool isSetupFinished() const;
    Font& font(FontKind kind);
private:
    /* 0x60 */ mem::ExplicitAutoDeleteArray<Font, 9> mFontArray;
};

}

#endif
