#ifndef DONUT_SCN_STEP_SPSTOP_IEVENTRECEIVER_HPP
#define DONUT_SCN_STEP_SPSTOP_IEVENTRECEIVER_HPP

/* clang-format off */

namespace scn { namespace step { namespace spstop {

class Manager;

class IEventReceiver
{
public:
    /* 0x8 */ virtual void onSuperStopStarted(const Manager &rManager);
    /* 0xC */ virtual void onSuperStopFinished(const Manager &rManager);
};

}}}

#endif
