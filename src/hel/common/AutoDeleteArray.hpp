#ifndef HEL_AUTO_DELETE_ARRAY_HPP
#define HEL_AUTO_DELETE_ARRAY_HPP

#include "hel/common/Array.hpp"
#include <memory>

namespace hel {
namespace common {

template <typename T, size_t S>
class AutoDeleteArray {
public:
    ~AutoDeleteArray() {
        for (; mSize > 0; mSize--) {
            u32 mSizeMinus1 = mSize - 1;

            T* val = mArray[mSizeMinus1];


            delete val;
        }
    }

    void add(std::auto_ptr<T>);

public:
    /* 0x0 */ u32 mSize;
    /* 0x4 */ Array<T*, S> mArray;
};

} // common
} // hel

#endif
