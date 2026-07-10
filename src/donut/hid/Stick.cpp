#pragma peephole off
#include <donut/hid/Stick.hpp>

using hid::Stick;

Stick::Stick(int arg1)
    : m_0(arg1)
    , mX(0)
    , mY(0)
{ }

void Stick::update(int _x, int _y) {
    mX = _x;
    mY = _y;
}

hel::math::Vector2 Stick::normalized() const {
    f32 yNormalized = (f32)mY / (f32)m_0;
    f32 xNormalized =  (f32)mX / (f32)m_0;

    return hel::math::Vector2(xNormalized, yNormalized);
}
