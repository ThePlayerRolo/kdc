#ifndef DONUT_OCOLL_COLLDATATABLE_HPP
#define DONUT_OCOLL_COLLDATATABLE_HPP

#include "ocoll/AttackData.hpp"

namespace ocoll {
    class CollDataTable {
    public:
        AttackData& getAttackData(u32 index) const;
    };
};

#endif
