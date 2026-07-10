#pragma peephole off
#include <donut/hid/SimpleGCHID.hpp>

using hid::SimpleGCHID;
using hid::GCUpdateData;

SimpleGCHID::SimpleGCHID()
    : mMainStick(128)
    , mSubStick(128)
{
    GCUpdateData updateData = {};
    update(updateData);
    update(updateData);
}

//https://decomp.me/scratch/deYz1
void SimpleGCHID::update(const GCUpdateData& rUpdateData) {
    mPrevUpdateData.m_0 = rUpdateData.m_0;
    mPrevUpdateData.m_8 = rUpdateData.m_8;
    if (mPrevUpdateData.m_0 == false) {
        GCUpdateData data = {};
    }
    mButton.update(mPrevUpdateData.m_4);
    mMainStick.update(mPrevUpdateData.m_8, mPrevUpdateData.m_C);
    mSubStick.update(mPrevUpdateData.m_10, mPrevUpdateData.m_14);
}

//https://decomp.me/scratch/yWpcs
hid::Button SimpleGCHID::button() const {
    return mButton;
}

hid::Stick SimpleGCHID::mainStick() const {
    return mMainStick;
}

hid::Stick SimpleGCHID::subStick() const {
    return mSubStick;
}

GCUpdateData SimpleGCHID::prevUpdateData() const {
    return mPrevUpdateData;
}

//NOTE: All functions below are code merged into others. Refer to the header for more details

bool SimpleGCHID::isConnected() const {
    return mPrevUpdateData.m_0;
}
