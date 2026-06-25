#ifndef DONUT_G3D_MODEL_CONTEXT_HPP
#define DONUT_G3D_MODEL_CONTEXT_HPP

#include "g3d/ResModelContext.hpp"
#include "g3d/ModelBufferOption.hpp"
#include "mem/Memory.hpp"

namespace g3d {
    class ModelContext : public ResModelContext {
    public:
      ModelContext(const ResModelContext &rModelCtx, const ModelBufferOption& rBufferOptions,
                   u32 maxNumChildren, u32 numView, mem::IAllocator& rAllocator, bool isCreateNodeLocalMtx);

    static mem::IAllocator& DefaultAllocator();
    static ModelBufferOption DefaultModelBufferOption();

    // NOTE: Is merged into nw4r::ut::DvdFileStream::GetOffsetAlign() const
    static u32 DefaultMaxNumChildren();
    //NOTE: Is merged into nw4r::ut::detail::ResFontBase::GetType() const
    static u32 DefaultNumView();
    //NOTE: Is merged into nw4r::ut::DvdFileStream::CanCancel() const
    static bool DefaultIsCreateNodeLocalMtx();
    public:
        /* 0x2C */ ModelBufferOption mBufferOptions;
        /* 0x3C */ u32 mNumChildrenMax;
        /* 0x40 */ u32 mViewNum;
        /* 0x44 */ mem::IAllocator& mAllocator;
        /* 0x48 */ bool mIsCreateNodeLocalMtx;
    };
}

#endif
