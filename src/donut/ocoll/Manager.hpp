#ifndef DONUT_OCOLL_MANAGER_HPP
#define DONUT_OCOLL_MANAGER_HPP

#include <types.h>
#include "ocoll/CollDataTable.hpp"

namespace ocoll {

class Manager {
public:

private:
    /* 0x0000 */ STRUCT_FILL(0x2024);
    /* 0x2024 */ CollDataTable* mCollDataTable;
    /* 0x2028 */ STRUCT_FILL(0x20);
};

}

#endif
