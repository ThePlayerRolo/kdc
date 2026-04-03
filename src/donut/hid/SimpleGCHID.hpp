#ifndef DONUT_HID_SIMPLE_GAMECUBE_HID_HPP
#define DONUT_HID_SIMPLE_GAMECUBE_HID_HPP

#include <donut/hid/Button.hpp>
#include <donut/hid/Stick.hpp>

namespace hid {
    struct GCUpdateData {
        /* 0x00 */ bool m_0;
        /* 0x04 */ s32 m_4;
        /* 0x08 */ s32 m_8;
        /* 0x0C */ s32 m_C;
        /* 0x10 */ s32 m_10;
        /* 0x14 */ s32 m_14;
    };

    class SimpleGCHID {
    public:
        SimpleGCHID();

        void update(const GCUpdateData& rUpdateData);

        Button button() const;
        Stick mainStick() const;
        Stick subStick() const;

        //NOTE: Merged into nrel::ezrender::GXSettingFor2D::orthoCameraSetting() const
        GCUpdateData prevUpdateData() const;
        //NOTE: Merged into effect::detail::GenContext::dataType() const
        bool isConnected() const;

    private:
        /* 0x00 */ GCUpdateData mPrevUpdateData;
        /* 0x18 */ Button mButton;
        /* 0x24 */ Stick mMainStick;
        /* 0x30 */ Stick mSubStick;
    };
}

#endif
