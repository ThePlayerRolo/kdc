#ifndef MEM_EXPLICIT_AUTO_DELETE_ARRAY_HPP
#define MEM_EXPLICIT_AUTO_DELETE_ARRAY_HPP

#include "hel/common/Array.hpp"
#include "mem/Memory.hpp"

namespace mem {

template <typename T, size_t S>
class ExplicitAutoDeleteArray {
public:

    ExplicitAutoDeleteArray(mem::IAllocator& rAllocator) : mAllocator(rAllocator), mSize(0), mArray() { }

    ~ExplicitAutoDeleteArray() {
        for (; mSize > 0; mSize--) {
            u32 mSizeMinus1 = mSize - 1;

            T* val = mArray[mSizeMinus1];


            delete val;
        }
    }

    T& operator[](size_t index) {
        // Most likely debug stuff stripped
        if(hel::common::ArrayUtil::RangeCheck(index, mSize)) { s32 stack[6]; }

        return *mArray[index];
    }

public:
    /* 0x0 */ mem::IAllocator& mAllocator;
    /* 0x4 */ u32 mSize;
    /* 0x8 */ hel::common::Array<T*, S> mArray;
};

} // mem

#endif
