#include "scn/step/spstop/Manager.hpp"

using namespace scn::step::spstop;

Manager::Manager()
{
    m_204 = false;
    mIsStopped = false;
}

Manager::~Manager()
{
}

bool Manager::isStopped() const
{
    return mIsStopped;
}

void Manager::update()
{
    u32 index;
    IEventReceiver *pEventReceiver;

    if (m_204 != mIsStopped)
    {
        mIsStopped = m_204;
        if (m_204 == false)
        {
            for (index = 0; index < mEventReceiver.mEntries; index++)
            {
                pEventReceiver = mEventReceiver[index];
                pEventReceiver->onSuperStopStarted(*this);
            }
        }
        else
        {
            for (index = 0; index < mEventReceiver.mEntries; index++)
            {
                pEventReceiver = mEventReceiver[index];
                pEventReceiver->onSuperStopFinished(*this);
            }
        }
    }

    return;
}

void Manager::registerEventReceiver(IEventReceiver &rEventReceiver)
{
    if (mEventReceiver.mEntries != 128)
    {
        IEventReceiver *eventReceiver = mEventReceiver.mArray[mEventReceiver.mEntries];
        *eventReceiver = rEventReceiver;
        mEventReceiver.mEntries = mEventReceiver.mEntries + 1;
    }

    if (mIsStopped != false)
    {
    }
}

void Manager::unregisterEventReceiver(IEventReceiver &rEventReceiver)
{
}
