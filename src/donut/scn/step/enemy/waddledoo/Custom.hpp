#ifndef DONUT_SCN_STEP_ENEMY_WADDLE_DOO_CUSTOM_HPP
#define DONUT_SCN_STEP_ENEMY_WADDLE_DOO_CUSTOM_HPP

#include <hel/common/RuntimeTypeInfo.hpp>
#include "scn/step/enemy/CustomBase.hpp"

namespace scn { namespace step { namespace enemy {
    namespace waddledoo {
        class Custom : public CustomBase {
        public:
            Custom(Enemy&);
            /* 0x08 */ virtual void GetRuntimeTypeInfo() const;
            /* 0x0C */ virtual ~Custom();
        };
    }
}}};

HEL_RTTI_IMPL_PARENT(Custom, scn::step::enemy::CustomBase);
#endif
