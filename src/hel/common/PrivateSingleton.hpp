#ifndef HEL_COMMON_PRIVATE_SINGLETON_HPP
#define HEL_COMMON_PRIVATE_SINGLETON_HPP

#include <hel/common/NonCopyable.hpp>
#include <types.h>

namespace hel { namespace common {

//I hate this class so much
template <typename T>
class PrivateSingleton : public  NonCopyable {
public:
    //TODO: Get this constructor to actually inline
    inline PrivateSingleton() {
        isExist_ = true;
    }

    ~PrivateSingleton() {
        isExist_ = false;
    }

private:
    //TODO: This needs to be instinated inside the tus of the classes that use PrivateSingleton
    static bool isExist_;
};

} // common
} // hel

#endif
