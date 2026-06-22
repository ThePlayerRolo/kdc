#ifndef HEL_COMMON_RUNTIMETYPEINFO_HPP
#define HEL_COMMON_RUNTIMETYPEINFO_HPP

#include <types.h>

namespace hel { namespace common {

class RuntimeTypeInfo {
public:
    static char* NoName() {
        return "no name class";
    }

    RuntimeTypeInfo(const RuntimeTypeInfo* pParent, const char* pName) DECOMP_DONT_INLINE
        : mParent((RuntimeTypeInfo*)pParent)
        , mName(pName)
    { }

    /* 0x0 */ RuntimeTypeInfo* mParent;
    /* 0x4 */ const char* mName;
};

#define HEL_RTTI_IMPL_PARENT(T, P) \
namespace hel { \
namespace common { \
template <typename T> \
const RuntimeTypeInfo& RuntimeTypeInfoImpl() { \
    static RuntimeTypeInfo ti((RuntimeTypeInfo*)&RuntimeTypeInfoImpl<P>(), RuntimeTypeInfo::NoName()); \
    return ti; \
} \
}}

#define HEL_RTTI_IMPL_NO_PARENT(T) \
namespace hel { \
namespace common { \
template <typename T> \
const RuntimeTypeInfo& RuntimeTypeInfoImpl() { \
    static RuntimeTypeInfo ti(nullptr, RuntimeTypeInfo::NoName()); \
    return ti; \
} \
}}

}}

#endif
