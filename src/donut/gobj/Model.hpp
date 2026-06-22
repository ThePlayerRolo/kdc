#ifndef DONUT_GOBJ_MODEL
#define DONUT_GOBJ_MODEL

#include "gobj/Anim.hpp"

namespace g3d {
    class CharaModel;
}

namespace gobj {
    class Model {

        /* 0x08 */ virtual ~Model();
        /* 0x0C */ virtual g3d::CharaModel* g3dModel();

    public:
        STRUCT_FILL(0x1D0);
    };

};

#endif
