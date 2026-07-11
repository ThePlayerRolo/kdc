#ifndef DONUT_SCN_STEP_ENEMY_SUPERSTOP_HPP
#define DONUT_SCN_STEP_ENEMY_SUPERSTOP_HPP

#include "scn/step/enemy/Enemy.hpp"
#include "scn/step/spstop/Manager.hpp"

/* clang-format off */
namespace scn { namespace step { namespace enemy {

class SuperStop : public scn::step::spstop::IEventReceiver
{
public:
    SuperStop(Enemy &rEnemy);
    virtual ~SuperStop();
    
    void onObjCollReactHit();
    virtual inline void onSuperStopStarted(const scn::step::spstop::Manager &rManager);
    virtual void onSuperStopFinished(const scn::step::spstop::Manager &rManager);
private:
    /* 0x4 */ Enemy *mEnemy;
    /* 0x8 */ bool m_8;
};

}}}

/* clang-format on */

#endif
