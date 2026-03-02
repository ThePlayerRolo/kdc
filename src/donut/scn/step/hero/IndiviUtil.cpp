#include "scn/step/hero/IndiviUtil.h"

using namespace scn::step::hero;

float IndiviUtil::CenterOffset(Kind kind) {
    switch (kind) {
        case KIND_KIRBY_1:
        case KIND_KIRBY_2:
        case KIND_KIRBY_3:
        case KIND_KIRBY_4:
            return 0.5f;
        case KIND_META:     return 0.5f;
        case KIND_DEDEDE:   return 0.75f;
        case KIND_DEE:      return 0.5f;
        default:            return 0.5f;
    }
}

void IndiviUtil::VacuumAttackerOffset() {
    m_0 = 0.0f;
    m_4 = 0.75f;
}

// https://decomp.me/scratch/HpNqE
bool IndiviUtil::IsKirby(Kind kind) {
    return kind < KIND_META;
}

bool IndiviUtil::IsMeta(Kind kind) {
    return kind == KIND_META;
}

bool IndiviUtil::IsDedede(Kind kind) {
    return kind == KIND_DEDEDE;
}

bool IndiviUtil::IsDee(Kind kind) {
    return kind == KIND_DEE;
}

bool IndiviUtil::CanHover(Kind kind) {
    if (IsKirby(kind)) {
        return true;
    }

    return IsDedede(kind);
}
