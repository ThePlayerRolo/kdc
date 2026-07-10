#ifndef MINTVM_NONCOPYABLE_HPP
#define MINTVM_NONCOPYABLE_HPP

#include <types.h>

namespace mintvm {

class NonCopyable {
protected:
    NonCopyable() { }
    //NOTE: Merged scn::IScene::~IScene
    ~NonCopyable() DONT_INLINE {}
    NonCopyable(const NonCopyable& rOther);
};
}

#endif
