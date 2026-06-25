#pragma peephole off
#include "g3d/ModelContext.hpp"

namespace g3d {

    mem::IAllocator& ModelContext::DefaultAllocator() {
        return mem::Memory::Instance->sceneHeap();
    }
    ModelBufferOption ModelContext::DefaultModelBufferOption() {
        ModelBufferOption options = ModelBufferOption();
        options.addAnimMatColor();
        options.addAnimTexPattern();
        options.addAnimTexSRT();
        options.addAnimVisible();
        options._B = true;
        options._4 = true;
        options._5 = true;
        return options;

    }

    ModelContext::ModelContext(const ResModelContext &rModelCtx, const ModelBufferOption& rBufferOptions,
        u32 maxNumChildren, u32 numView, mem::IAllocator& rAllocator, bool isCreateNodeLocalMtx)
    : ResModelContext(rModelCtx)
    , mBufferOptions(rBufferOptions)
    , mNumChildrenMax(maxNumChildren)
    , mViewNum(numView)
    , mAllocator(rAllocator)
    , mIsCreateNodeLocalMtx(isCreateNodeLocalMtx)
    {
    }

    u32 ModelContext::DefaultMaxNumChildren() { return 4; }
    u32 ModelContext::DefaultNumView() { return 2; }
    bool ModelContext::DefaultIsCreateNodeLocalMtx() { return true; }
}
