#ifndef DONUT_SCN_STEP_CORE_SPHEREACCESSOR_HPP
#define DONUT_SCN_STEP_CORE_SPHEREACCESSOR_HPP

// functionality has been cut from the game's code

#include <types.h>

namespace scn { namespace step {
    class Component;
    namespace core {
    class SphereAccessor {
    public:
        //NOTE: Merged into nw4r::g3d::Camera::Camera(nw4r::g3d::CameraData*)
        SphereAccessor(Component&);

        //NOTE: Merged into nw4r::ut::DvdFileStream::CanCancel() const
        bool isGet(u32) const;
     };
}}}

#endif
