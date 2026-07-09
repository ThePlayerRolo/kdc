#ifndef DONUT_FONT_FONT_HPP
#define DONUT_FONT_FONT_HPP

#include <nw4r/ut/ut_ResFont.h>
#include <hel/common/FixedString.hpp>

namespace font {
    class Font {
    public:
        Font(const char* pFilePath, const char* pName);
        ~Font();
        void load();
        void unload();
        bool loaded() const;
        const hel::common::FixedString<32>& name() const;
        nw4r::ut::ResFont* font();
    private:
        /* 0x00 */ hel::common::FixedString<80> mFilePath;
        /* 0x50 */ hel::common::FixedString<32> mName;
        /* 0x70 */ nw4r::ut::ResFont mFont;
        /* 0x8C */ bool mLoaded;
    };

}

#endif
