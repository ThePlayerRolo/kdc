#ifndef HEL_COMMON_NONCOPYABLE_HPP
#define HEL_COMMON_NONCOPYABLE_HPP

namespace hel { namespace common {

class NonCopyable {
public:
    NonCopyable() { }
    //NOTE: Merged scn::IScene::~IScene
    //TODO: Get this to inline in AppImpl but  not inline in PrivateSIngleton
    ~NonCopyable() {}
private:
    NonCopyable(const NonCopyable& rOther);
};

}}

#endif
