#pragma peephole off
#include "font/FontManager.hpp"
#include "mem/Memory.hpp"

namespace font {
    // https://decomp.me/scratch/DPpg5
    FontManager::FontManager()
        : mem::AutoHeapExp(mem::Memory::Instance->mem2FixHeap(), 0xC00, "Font")
        , mFontArray(obj())
    {

    }

    // https://decomp.me/scratch/YBXbx
    void FontManager::setup() {
        for (u32 i = 0; i < 9; mFontArray.mSize++, i++) {
            FontKind kind = (FontKind)i;
            const char* fontName = FontKindUtil::Name(kind);
            const char* fontFilePath = FontKindUtil::FilePath(kind).str();

            mFontArray.mArray[mFontArray.mSize] = new (mFontArray.mAllocator) Font(fontFilePath, fontName);
        }

        for (u32 i = 0; i <= 6; i++) {
            mFontArray[i].load();
        }
    }

    bool FontManager::isSetupFinished() const {
        return mFontArray.mSize != 0;
    }

    Font& FontManager::font(FontKind kind) {
        return mFontArray[kind];
    }
}
