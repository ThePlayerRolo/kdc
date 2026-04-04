#ifndef HEL_TRAITS_HPP
#define HEL_TRAITS_HPP

#include <types.h>

namespace hel {
namespace common {

template <typename T>
class Traits {
public:
    static void Strncpy(T* arg1, const T* arg2, u32 param3);

private:
};

} // common
} // hel

#endif
