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
        nw4r::g3d::ResMdl* obj() const;
    public:
        /* 0x00 */ ResFileAccessor mFile;
        /* 0x04 */ nw4r::g3d::ResMdl mObj;
    };
}

#endif

/*
--> isValid__Q23g3d8ResModelCFv is duplicated by isConstruct__Q23mem43ExplicitScopedPtr<Q23app16HIDErrorMenuImpl>CFv, size = 16

--> obj__Q23g3d8ResModelCFv is duplicated by GetZeroBufferAddress__Q44nw4r3snd6detail9AxManagerFv, size = 8
*/
