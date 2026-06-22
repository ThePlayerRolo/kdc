#pragma peephole off

#include "scn/step/enemy/CustomBase.hpp"
#include <hel/common/RuntimeTypeInfo.hpp>

using scn::step::enemy::ICustom;
using scn::step::enemy::CustomBase;

HEL_RTTI_IMPL_PARENT(CustomBase, ICustom);

CustomBase::CustomBase(Enemy& rObj)
    : mObj(rObj)
{ }

bool CustomBase::onInit() { return false; }

bool CustomBase::onHitPointIsZero() { return false; }

bool CustomBase::onVacuumReceive() { return false; }

bool CustomBase::onVacuumResist() { return false; }

bool CustomBase::onDamaged() { return false; }

//onInWater

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
