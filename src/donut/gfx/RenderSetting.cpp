#pragma peephole off
#include <donut/gfx/RenderSetting.hpp>
#include <donut/gfx/VISetting.hpp>

using gfx::RenderSetting;
namespace {
    static const f32 VIEWPORT_NEAR = 0.0f;

    void t_setCopyClear() {
        GXColor copyClearColor = {0, 0, 0, 255};
        GXSetCopyClear(copyClearColor, 0xFFFFFF);
    }
}

RenderSetting::RenderSetting()
    : mVISetting(gfx::VISetting::Instance->object())
    , mType(TYPE_0)
    , m_8(0)
    , mDirty(true)
    , m_D(false)
    , mRect(0.0f, 0.0f, rmode()->mRenderModeObj.fbWidth, rmode()->mRenderModeObj.xfbHeight)
    , mRect2(0.0f, 0.0f, rmode()->mRenderModeObj.fbWidth, rmode()->mRenderModeObj.xfbHeight)
    , m_30(0)
{
    Instance = this;
}

RenderSetting::Rect::Rect(f32 left, f32 top, f32 right, f32 bottom)
    : mLeft(left)
    , mTop(top)
    , mRight(right)
    , mBottom(bottom)
{ }

RenderSetting::~RenderSetting() {
    Instance = nullptr;
}

gfx::VISettingPreset* RenderSetting::rmode() const {
    u32 mMode = mVISetting->mMode;

    switch (mType) {
        case  TYPE_1:
            switch (mMode) {
                case 0:
                    return mVISetting->rmode(1);
                case 2:
                    return mVISetting->rmode(3);
                case 7:
                    return mVISetting->rmode(8);
                case 9:
                    return mVISetting->rmode(10);
            }
            break;
        case TYPE_2:
            switch (mMode) {
                case 1:
                    return mVISetting->rmode(0);
                case 3:
                    return mVISetting->rmode(2);
                case 8:
                    return mVISetting->rmode(7);
                case 10:
                    return mVISetting->rmode(9);
            }
    }
    return (VISettingPreset*)mVISetting->mRenderModeObj;
}
