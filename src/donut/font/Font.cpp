#pragma peephole off
#include "font/Font.hpp"
#include "file/FileAccessor.hpp"

namespace font {
    Font::Font(const char* pFilePath, const char* pName)
        : mFilePath(pFilePath)
        , mName(pName)
        , mFont()
        , mLoaded(false)
    { }

    Font::~Font() {
        if (mLoaded) {
            unload();
        }
    }

    void Font::load() {
        mFont.SetResource(file::FileAccessor(mFilePath.str(), false).block().mStartAddress);
        mLoaded = true;
    }

    void Font::unload() {
        mFont.RemoveResource();
        mLoaded = false;
    }

    bool Font::loaded() const {
        return mLoaded;
    }

    const hel::common::FixedString<32>& Font::name() const {
        return mName;
    }

    nw4r::ut::ResFont* Font::font() {
        return &mFont;
    }
}
