#pragma peephole off
#include "g3d/CameraAccessor.hpp"

namespace g3d {
    hel::math::Matrix34 CameraAccessor::viewMtx() const {
        hel::math::Matrix34 mtx;
        GetCameraMtx(&mtx.mBaseMtx);
        return mtx;
    }

    void CameraAccessor::setViewMtx(const hel::math::Matrix34& rViewMtx) const {
        const_cast<CameraAccessor*>(this)->SetCameraMtxDirectly(rViewMtx.mBaseMtx);
    }

    void CameraAccessor::setPosition(const hel::math::Vector3& rPosition) const {
        if (&rPosition == nullptr) return;

        //TODO: Is there a cleaner way to get this VEC3 cast?
        const_cast<CameraAccessor*>(this)->SetPosition(*(const nw4r::math::VEC3*)&rPosition);
    }

    nw4r::g3d::Camera::PostureInfo CameraAccessor::getPosture() const {
        nw4r::g3d::Camera::PostureInfo postureInfo;
        const_cast<CameraAccessor*>(this)->GetPosture(&postureInfo);
        return postureInfo;
    }

    void CameraAccessor::setPosture(const nw4r::g3d::Camera::PostureInfo& rPostureInfo) const {
        const_cast<CameraAccessor*>(this)->SetPosture(rPostureInfo);
    }

    void CameraAccessor::setProjOrtho(f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 far) const {
        const_cast<CameraAccessor*>(this)->SetOrtho(top, bottom, left, right, near, far);
    }

    void CameraAccessor::setProjPerspective(f32 fovy, f32 aspect, f32 near, f32 far) const {
        const_cast<CameraAccessor*>(this)->SetPerspective(fovy, aspect, near, far);
    }

    f32 CameraAccessor::getProjFovy() const {
        return const_cast<CameraAccessor*>(this)->ref().projFovy;
    }

    f32 CameraAccessor::getProjAspect() const {
        return const_cast<CameraAccessor*>(this)->ref().projAspect;
    }

    f32 CameraAccessor::getProjNear() const {
        return const_cast<CameraAccessor*>(this)->ref().projNear;
    }

    f32 CameraAccessor::getProjFar() const {
        return const_cast<CameraAccessor*>(this)->ref().projFar;
    }

    //NOTE: All functions below are code merged into others. Refer to the header for more details

    CameraAccessor::CameraAccessor(const nw4r::g3d::Camera& rCamera) : nw4r::g3d::Camera(rCamera) { }
};
