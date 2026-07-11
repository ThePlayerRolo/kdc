#ifndef HEL_COMMON_MUTABLEARRAY_HPP
#define HEL_COMMON_MUTABLEARRAY_HPP

#include "hel/common/Array.hpp"

/* clang-format off */
namespace hel { namespace common {

template <typename T, size_t S>
class MutableArray {
public:
    MutableArray() : mEntries(0), mArray() {};
    ~MutableArray();
    T &operator[](size_t size);
public:
    /* 0x0 */ u32 mEntries;
    /* 0x4 */ Array<T, S> mArray;
};
}}
#endif
