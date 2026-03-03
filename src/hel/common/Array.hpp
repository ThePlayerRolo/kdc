#ifndef HEL_ARRAY_HPP
#define HEL_ARRAY_HPP

#include <types.h>

namespace hel {
namespace common {

template <typename T, size_t S>
class Array {
public:
    T& operator[](size_t index);
private:
    /* 0x0 */ T mArray[S];
};

} // common
} // hel

#endif
