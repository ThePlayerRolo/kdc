#ifndef DONUT_GFX_XFBMANAGER_HPP
#define DONUT_GFX_XFBMANAGER_HPP

#include <donut/gfx/VISetting.hpp>
#include <donut/mem/DataBlock.hpp>

namespace gfx {

class XFBManager {
public:

    XFBManager(const gfx::VISetting&);

    void* drawTargetXFB();
    void changeDrawTargetXFB();

    void* target1();
    void* target2();

    /* 0x0 */ mem::DataBlock m_0;
    /* 0xC */ mem::DataBlock m_C;
    /* 0x18 */ bool m_18;

};

}

#endif
