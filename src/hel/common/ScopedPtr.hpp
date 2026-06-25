#ifndef HEL_COMMON_SCOPEDPTR_HPP
#define HEL_COMMON_SCOPEDPTR_HPP

#include <types.h>

namespace hel { namespace common {

namespace ScopedPtrUtil {
    // NOTE: Merged into DefaultSwitchThreadCallback
    bool CheckPointerIsValid(const void* pPtr); //Stubbed in final release
}

template<typename T>
class ScopedPtr {
public:
    // TODO: Remove DONT_INLINE ( Could be related to CheckPointerIsValid and debug stuff)
    ScopedPtr(T* pPtr) DONT_INLINE : ptr(pPtr) { }

    ~ScopedPtr() {
        if (ptr != nullptr) {
            delete ptr;
        }
    }
    void reset(T* ptr);

    T* operator->() const {
        // Most likely some debug stuff was stripped from release
        if (ScopedPtrUtil::CheckPointerIsValid(ptr)) { s32 stack[5]; }
        return ptr;
    }

private:
    T* ptr;
};

} // common
} // hel
#endif
