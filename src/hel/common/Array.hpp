#ifndef HEL_ARRAY_HPP
#define HEL_ARRAY_HPP

#include <types.h>

namespace hel {
namespace common {
    namespace ArrayUtil {
        //Stubbed out and merged into DefaultSwitchThreadCallback
        bool RangeCheck(u32 index, u32 size);
    };

template <typename T, size_t S>
class Array {
public:

    Array() : mArray() { }

    ~Array();
    T& operator[](size_t index) DONT_INLINE {
        ArrayUtil::RangeCheck(index, S);
        return mArray[index];
    }
private:
    /* 0x0 */ T mArray[S];
};

} // common
} // hel

#endif
