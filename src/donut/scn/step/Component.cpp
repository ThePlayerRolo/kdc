#include "scn/step/Component.hpp"
#include "mem/ExplicitScopedPtr.hpp"
#include "scn/step/debug/GeneralDrawer.hpp"

using namespace scn::step;
using mem::ExplicitScopedPtrUtil::CheckPointerIsValid;

Component::~Component() { }

core::SphereAccessor* Component::sphereAccessor() {
    CheckPointerIsValid(mSphereAccessor.operator->());
    return mSphereAccessor.operator->();
}

debug::GeneralDrawer* Component::debugGeneralDrawer() {
    CheckPointerIsValid(mDebugGeneralDrawer.operator->());
    return mDebugGeneralDrawer.operator->();
}

debug::ObjInfoRepos* Component::debugObjInfoRepos() {
    CheckPointerIsValid(mDebugObjInfoRepos.operator->());
    return mDebugObjInfoRepos.operator->();
}
