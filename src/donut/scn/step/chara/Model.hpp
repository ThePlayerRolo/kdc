#ifndef DONUT_SCN_STEP_CHARA_MODEL
#define DONUT_SCN_STEP_CHARA_MODEL

#include "gobj/Anim.hpp"

namespace g3d {
    class CharaModel;
}

namespace scn { namespace step { namespace chara {
    class Model {
    public:
        /* 0x08 */ virtual ~Model();

        gobj::Anim* anim();
    public:
        STRUCT_FILL(0x368);
    };

}}}

#endif
