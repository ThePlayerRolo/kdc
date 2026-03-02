#include "scn/step/hero/IndiviUtil.h"

using namespace scn::step::hero;

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
