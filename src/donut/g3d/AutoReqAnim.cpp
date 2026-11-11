#include "g3d/AutoReqAnim.hpp"
#include "g3d/AutoReqAnimReqInfo.hpp"
#include "g3d/ResAnmAutoReq.hpp"

namespace g3d {
    AutoReqAnim::AutoReqAnim(const ResAnmAutoReq& rRes)
        : ResAnmAutoReq(rRes)
        , mPrevFrame(0.0f)
        , mCurFrame(0.0f)
        , mFrameRate(0.0f)
        , mIsLooped(false)
    {
        setFrame(0.0f);
    }

    void AutoReqAnim::setFrame(f32 frame) {
        mPrevFrame = frame;
        mCurFrame = frame;
        mFrameRate = 0.0f;
        mIsLooped = false;
    }

    void AutoReqAnim::updateFrame(f32 frame, f32 frameRate, bool isLooped) {
        mPrevFrame = mCurFrame;
        mCurFrame = frame;
        mFrameRate = frameRate;
        mIsLooped = isLooped;
    }

    void AutoReqAnim::requestOnSetFrame(IAutoReqAnimCallback& rCallback) const {
        Header* header = headerRef();
        if (header->mSize != 0) {
            requestIN(rCallback, calcRecordIndex(*header, mPrevFrame));
        }
    }

    void AutoReqAnim::requestOnUpdateFrame(IAutoReqAnimCallback& rCallback) const {
        if (mFrameRate == 0.0f) return;

        Header* header = headerRef();
        if (header->mSize == 0) return;

        u32 recordIndexPrev = calcRecordIndex(*header, mPrevFrame);
        u32 recordIndexCur = calcRecordIndex(*header, mCurFrame);

        if (mIsLooped || recordIndexPrev != recordIndexCur) {
            bool positiveFrameRate = 0.0f <= mFrameRate;

            while (recordIndexPrev != recordIndexCur)
            {
                if (recordIndexPrev == header->mSize) {
                    recordIndexPrev = 0;
                }

                if (positiveFrameRate) {
                    recordIndexPrev  = (recordIndexPrev == 0) ? header->mSize : recordIndexPrev - 1;
                }
                requestIN(rCallback, recordIndexPrev);
            }
        }
    }

    const xdata::XData* AutoReqAnim::xdata() const {
        return data();
    }

    AutoReqAnim::Header* AutoReqAnim::headerRef() const {
        const xdata::XData* data = xdata();
        if (data->isValidData()) {
            return (Header *)&data[1];
        }
        return nullptr;
    }

    const char* AutoReqAnim::toXDataString(unsigned int idx) const {
        return (char*)reference(idx);
    }

    u32* AutoReqAnim::reference(unsigned int idx) const {
        const xdata::XData* data = xdata();
        if (!data->isValidData()) {
            return nullptr;
        }
        if (idx < sizeof(xdata::XData) || *(((u32*)data) + 2) < idx) {
            return nullptr;
        }
        return &(((u32*)data)[idx]);
    }
}
