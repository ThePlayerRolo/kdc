#ifndef DONUT_SCN_STEP_HERO_INDIVIUTIL_H
#define DONUT_SCN_STEP_HERO_INDIVIUTIL_H

#include "scn/step/common/Param.h"
#include "scn/step/hero/Hero.h"

namespace scn { namespace step { namespace hero {

enum Kind {
    KIND_KIRBY      = 0,
    KIND_KIRBY_1    = 0,
    KIND_KIRBY_2    = 1,
    KIND_KIRBY_3    = 2,
    KIND_KIRBY_4    = 3,
    KIND_META       = 4,
    KIND_DEDEDE     = 5,
    KIND_DEE        = 6,
};

struct NodeAttach { };
struct NodeAttachParam { };

class IndiviUtil {
public:
    static common::Param* Param(const Hero&);
    static float CenterOffset(Kind);
    static void InitNodeAttach(NodeAttach&, Kind);
    static bool IsKirby(Kind kind);
    static bool IsMeta(Kind kind);
    static bool IsDedede(Kind kind);
    static bool IsDee(Kind kind);
    static bool CanHover(Kind kind);

    void VacuumAttackerOffset();
private:
    /* 0x0 */ float m_0;
    /* 0x4 */ float m_4;
};

} // hero
} // step
} // scn

#endif
