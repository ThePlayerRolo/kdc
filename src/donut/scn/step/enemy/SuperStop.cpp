#include "scn/step/enemy/SuperStop.hpp"

using namespace scn::step::enemy;

SuperStop::SuperStop(Enemy &rEnemy)
{
    scn::step::spstop::Manager *pSuperStopManager;

    mEnemy = &rEnemy;
    m_8 = false;

    pSuperStopManager = mEnemy->mComponent->superStopManager();
    pSuperStopManager->registerEventReceiver(*this);
}

SuperStop::~SuperStop()
{
    scn::step::spstop::Manager *pSuperStopManager = mEnemy->mComponent->superStopManager();
    pSuperStopManager->unregisterEventReceiver(*this);
}

void SuperStop::onObjCollReactHit()
{
    scn::step::spstop::Manager *pSuperStopManager = mEnemy->mComponent->superStopManager();

    if (pSuperStopManager->isStopped())
    {
        // mEnemy->objStop();
    }
}

inline void SuperStop::onSuperStopStarted(const scn::step::spstop::Manager &rManager)
{
    m_8 = false;
}

void SuperStop::onSuperStopFinished(const scn::step::spstop::Manager &rManager)
{
    if (m_8 == false)
    {
        // mEnemy->objStop();
    }
}
