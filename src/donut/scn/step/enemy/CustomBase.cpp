#pragma peephole off

#include "scn/step/enemy/CustomBase.hpp"
#include <hel/common/RuntimeTypeInfo.hpp>
#include "scn/step/enemy/damage/StateDeadInWater.hpp"

using scn::step::enemy::ICustom;

HEL_RTTI_IMPL_PARENT(CustomBase, ICustom);

namespace scn { namespace step { namespace enemy {
    CustomBase::CustomBase(Enemy& rObj)
        : mObj(rObj)
    { }

    bool CustomBase::onInit() { return false; }

    bool CustomBase::onHitPointIsZero() { return false; }

    bool CustomBase::onVacuumReceive() { return false; }

    bool CustomBase::onVacuumResist() { return false; }

    bool CustomBase::onDamaged() { return false; }

    // https://decomp.me/scratch/N4Lky
    bool CustomBase::onInWater() {
        util::StateChanger<scn::step::enemy::IState, 256>* stateChanger = mObj.stateChanger();
        stateChanger->setNextState<damage::StateDeadInWater, Enemy*>(&mObj);

        return true;
    }

    bool CustomBase::onOutWater() { return false; }

    bool CustomBase::onRecover() { return false; }

    void CustomBase::onCaptured() {}

    void CustomBase::onDead() {}

    void CustomBase::onProcFixPos() {}

    bool CustomBase::reqCustomDeadEffect() { return false; }

    void CustomBase::setupSuperEnemyEffect() {}

    void CustomBase::GetRuntimeTypeInfo() const {
        hel::common::RuntimeTypeInfoImpl<CustomBase>();
    }

    //NOTE: All functions below are code merged into others. Refer to the header for more details

    scn::step::enemy::Enemy& CustomBase::obj() const {
        return mObj;
    }

    scn::step::enemy::Enemy& CustomBase::obj() {
        return mObj;
    }

    CustomBase::~CustomBase() { }
}}}
