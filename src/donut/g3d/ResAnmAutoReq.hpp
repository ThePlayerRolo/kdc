#ifndef DONUT_G3D_RES_ANM_AUTO_REQ_HPP
#define DONUT_G3D_RES_ANM_AUTO_REQ_HPP

namespace g3d {
    class ResAnmAutoReq {
    public:
        //NOTE: Merged into nw4r::g3d::LightObj::LightObj()
        ResAnmAutoReq();
        //NOTE: Merged into nw4r::g3d::Camera::Camera(nw4r::g3d::CameraData*)
        ResAnmAutoReq(const void*);

        //NOTE: Is merged into nrel::mem::ExpHeapBlockIterator::hasNext() const
        bool isValid() const;

        //NOTE: Is merged into GKI_getfirst
        void* data() const;
    private:
        /* 0x00 */ const void* mData;
    };
}

#endif
