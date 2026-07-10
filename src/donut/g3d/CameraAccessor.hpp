#ifndef DONUT_G3D_CAMERA_ACCESSOR_HPP
#define DONUT_G3D_CAMERA_ACCESSOR_HPP

#include <nw4r/g3d/g3d_camera.h>
#include <hel/math/Matrix34.hpp>
#include <hel/math/Vector3.hpp>

namespace g3d {
    class CameraAccessor : public nw4r::g3d::Camera {
    public:
        //NOTE: Merged into nw4r::ut::Color::Color(const nw4r::ut::Color&)
        CameraAccessor(const nw4r::g3d::Camera&);

        hel::math::Matrix34 viewMtx() const;
        void setViewMtx(const hel::math::Matrix34& rViewMtx) const;
        void setPosition(const hel::math::Vector3& rPosition) const;
        nw4r::g3d::Camera::PostureInfo getPosture() const;
        void setPosture(const nw4r::g3d::Camera::PostureInfo& rPostureInfo) const;
        void setProjOrtho(f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 far) const;
        void setProjPerspective(f32 fovy, f32 aspect, f32 near, f32 far) const;
        f32 getProjFovy() const;
        f32 getProjAspect() const;
        f32 getProjNear() const;
        f32 getProjFar() const;
    };
}

#endif
