#ifndef DONUT_G3D_GROUP_HPP
#define DONUT_G3D_GROUP_HPP

// Seems to be unused in this game and rtdl lol
#include <nw4r/g3d/g3d_scnobj.h>

namespace g3d {
    class Group : public nw4r::g3d::ScnGroup {
        //Only here for Group.cpp's Weak Symbol that gets linked
        void sceneClear();
    };
}

#endif
