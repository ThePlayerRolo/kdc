#ifndef DONUT_G3D_AUTO_REQ_ANIM_HPP
#define DONUT_G3D_AUTO_REQ_ANIM_HPP

#include "g3d/ResAnmAutoReq.hpp"

namespace g3d {
class AutoReqAnimReqInfo;

class IAutoReqAnimCallback {
public:
    /* 0x8 */ virtual ~IAutoReqAnimCallback();
    /* 0xC */ virtual void request(const AutoReqAnimReqInfo& rInfo);
};

class AutoReqAnim : public ResAnmAutoReq {
public:
    struct Header {
        /* 0x0 */ u32 mSize;
        /* 0x4 */ u32* m_4;
    };

    AutoReqAnim(const ResAnmAutoReq& rRes);

    f32 totalFrame() const;
    void setFrame(f32 frame);
    void updateFrame(f32 frame, f32 frameRate, bool isLooped);
    void requestOnSetFrame(IAutoReqAnimCallback& rCallback) const;
    void requestOnUpdateFrame(IAutoReqAnimCallback& rCallback) const;
    const xdata::XData* xdata() const DONT_INLINE;
    Header* headerRef() const;
    const char* toXDataString(unsigned int idx) const;
    u32 calcRecordIndex(const Header& rHeader, f32) const;
    u32* reference(unsigned int idx) const;
private:
    void requestIN(IAutoReqAnimCallback& rCallback, u32) const;
public:
    /* 0x04 */ f32 mPrevFrame;
    /* 0x08 */ f32 mCurFrame;
    /* 0x0C */ f32 mFrameRate;
    /* 0x10 */ bool mIsLooped;
};
}

#endif
