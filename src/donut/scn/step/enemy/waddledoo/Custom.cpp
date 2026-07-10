#pragma peephole off
#include "scn/step/enemy/waddledoo/Custom.hpp"

namespace scn { namespace step { namespace enemy { namespace waddledoo {
    Custom::Custom(Enemy& rObj)
        : CustomBase(rObj)
    { }

    void Custom::GetRuntimeTypeInfo() const {
        hel::common::RuntimeTypeInfoImpl<Custom>();
    }

    Custom::~Custom() { }

}}}}
