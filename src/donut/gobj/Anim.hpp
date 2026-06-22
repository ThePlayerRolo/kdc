#ifndef DONUT_GOBJ_ANIM
#define DONUT_GOBJ_ANIM

#include "gobj/AnimDesc.hpp"
#include "mem/IAllocator.hpp"

namespace effect {
    class Requestor;
}

namespace gobj {
    class Model;

    class Anim {
    public:
        Anim(const AnimDesc&, mem::IAllocator&, Model&, effect::Requestor&);

        f32 frameRate() const;
    };

};

#endif
