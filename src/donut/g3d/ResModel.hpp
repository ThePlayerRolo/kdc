#ifndef DONUT_G3D_RES_MODEL_HPP
#define DONUT_G3D_RES_MODEL_HPP

#include "g3d/ResModelContext.hpp"
#include "g3d/ResNode.hpp"

namespace g3d {
    class ResFileAccessor;

    class ResModel {
    public:
        ResModel(const ResModelContext& rResFile);

        // NOTE: Merged into scn::IScene::~IScene()
        ~ResModel();

        ResNode nodeByIndex(u32 idx) const;
        ResNode nodeByName(const char* pName) const;
        s32 nodeCount() const;

        //NOTE: Merged into mem::ExplicitScopedPtr<app::HIDErrorMenuImpl>::isConstruct() const
        bool isValid() const;

        //NOTE: Merged into nw4r::snd::detail::AxManager::GetZeroBufferAddress()
        nw4r::g3d::ResMdl* obj() const; /* TODO: Double check type */
    public:
        /* 0x00 */ ResFileAccessor mFile;
        /* 0x04 */ nw4r::g3d::ResMdl mObj;
    };
}

#endif
