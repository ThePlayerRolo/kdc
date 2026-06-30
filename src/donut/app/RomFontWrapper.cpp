#pragma peephole off
#include "app/RomFontWrapper.hpp"
#include "mem/Memory.hpp"

namespace app {
    RomFontWrapper::RomFontWrapper()
    : mBlock(nw4r::ut::RomFont::GetRequireBufferSize(), 32, mem::Memory::Instance->mem2FixHeap())
    , mFont()
    {
        mFont.Load(mBlock.block().mStartAddress);
    }

    RomFontWrapper::~RomFontWrapper() {
        mFont.Unload();
    }

    nw4r::ut::RomFont& RomFontWrapper::font() {
        return mFont;
    }
}
