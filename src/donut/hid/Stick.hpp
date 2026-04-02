#ifndef DONUT_HID_STICK_HPP
#define DONUT_HID_STICK_HPP

#include <hel/math/Vector2.hpp>

namespace hid {
    class Stick {
    public:
        Stick() {}
        Stick(int);
        void update(int _x, int _y);
        hel::math::Vector2 normalized() const;

        /* 0x0 */ int m_0;
        /* 0x4 */ int mX;
        /* 0x8 */ int mY;
    };
}

#endif
