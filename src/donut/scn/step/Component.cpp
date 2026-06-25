#include "scn/step/Component.hpp"
#include "mem/ExplicitScopedPtr.hpp"
#include "scn/step/debug/GeneralDrawer.hpp"

using namespace scn::step;
using mem::ExplicitScopedPtrUtil::CheckPointerIsValid;

Component::~Component() { }

core::SphereAccessor* Component::sphereAccessor() {
    return mSphereAccessor.operator->();
}

debug::GeneralDrawer* Component::debugGeneralDrawer() {
    return mDebugGeneralDrawer.operator->();
}

debug::ObjInfoRepos* Component::debugObjInfoRepos() {
    return mDebugObjInfoRepos.operator->();
}
