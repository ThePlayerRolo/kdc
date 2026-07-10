#ifndef DONUT_MINTVM_EXPLICITSINGLETON_HPP
#define DONUT_MINTVM_EXPLICITSINGLETON_HPP

#include "mintvm/NonCopyable.hpp"
#include "mintvm/MintAssert.hpp"

namespace mintvm {

template<typename T>
class ExplicitSingleton : public NonCopyable {
public:
    ~ExplicitSingleton();

    static bool IsExist() {
        return object_ != nullptr;
    }

    inline T* operator->() {
        return Instance();
    }

    inline const T* operator->() const {
        return Instance();
    }

    inline void operator=(T* pOther) {
        object_ = pOther;
    }

    inline bool operator!=(T* pOther) {
        return object_ != pOther;
    }

    static T* Instance() DONT_INLINE {
        MINT_ASSERT_FAIL_LINE(33, IsExist());
        return object_;
    }
private:
    static T* object_;
};

} // mintvm

#define DECL_MINTVM_EXPLICIT_SINGLETON(T) static mintvm::ExplicitSingleton<T> Instance;

#endif
