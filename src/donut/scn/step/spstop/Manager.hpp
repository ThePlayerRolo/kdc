#ifndef DONUT_SCN_STEP_SPSTOP_MANAGER_HPP
#define DONUT_SCN_STEP_SPSTOP_MANAGER_HPP

#include <types.h>

#include "hel/common/MutableArray.hpp"
#include "scn/step/spstop/IEventReceiver.hpp"

// clang-format off
namespace scn { namespace step { namespace spstop {

class Manager
{
public:
    Manager();
    ~Manager();
    bool isStopped() const;
    void update();
    void registerEventReceiver(IEventReceiver &rEventReceiver);
    void unregisterEventReceiver(IEventReceiver &rEventReceiver);
private:
    /* 0x000 */ hel::common::MutableArray<IEventReceiver *, 128> mEventReceiver; 
    /* 0x204 */ bool m_204;
    /* 0x205 */ bool mIsStopped;
};

}}}

// clang-format on

#endif
