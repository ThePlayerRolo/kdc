#ifndef DONUT_G3D_AUTO_REQ_ANIM_REQ_INFO_HPP
#define DONUT_G3D_AUTO_REQ_ANIM_REQ_INFO_HPP

#include <hel/common/FixedString.hpp>

namespace g3d {
    class AutoReqAnimReqInfo {
    public:
        AutoReqAnimReqInfo();

    public:
        /* 0x00 */ hel::common::FixedString<40> _0;
        /* 0x28 */ hel::common::FixedString<40> _28;
        /* 0x50 */ hel::common::FixedString<40> _50;
        /* 0x78 */ u8 _78;
        /* 0x79 */ u8 _79;
        /* 0x7A */ u8 _7A;
    };
}

#endif
