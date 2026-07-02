#ifndef DONUT_SCN_STEP_HERO_HERO_HPP
#define DONUT_SCN_STEP_HERO_HERO_HPP

#include <types.h>

#include "mem/ExplicitScopedPtr.hpp"
#include "scn/step/common/Param.hpp"
#include "scn/step/hero/Kind.hpp"

/* clang-format off */
namespace scn { namespace step { namespace hero {
    class Guard; 

    class Param { // todo: put this in its own file
    public:
        common::Param* indiviKirby() const;
        common::Param* indiviMeta() const;
        common::Param* indiviDedede() const;
        common::Param* indiviDee() const;
    };

    class Hero {
    public:
        Param* param() const;
        Kind kind() const; // code merged
        Guard* guard();
    private:
        u8 m_0[0x168 - 0x0];
        mem::ExplicitScopedPtr<Guard> mGuard;
    };
}}}
/* clang-format on */

#endif
