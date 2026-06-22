#ifndef DONUT_SCN_STEP_ENEMY_ENEMY_HPP
#define DONUT_SCN_STEP_ENEMY_ENEMY_HPP

#include <types.h>

namespace scn { namespace step {
    class Component;

    namespace enemy {
    class Enemy {
    public:
        ~Enemy();
    public:
        STRUCT_FILL(0x1B8);
    };

}}};

#endif
