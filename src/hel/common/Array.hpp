#ifndef HEL_ARRAY_HPP
#define HEL_ARRAY_HPP

#include <types.h>

/* clang-format off */

namespace hel {
namespace common {

template <typename T, size_t S>
class Array {
public:
    Array() : mData() {};
    T &operator[](size_t index);
public:
    /* 0x0 */ T mData[S];
};

} // common
} // hel

#endif
