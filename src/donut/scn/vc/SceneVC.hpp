#ifndef DONUT_SCN_VC_SCENE_VC_HPP
#define DONUT_SCN_VC_SCENE_VC_HPP

#include <hel/common/ScopedPtr.hpp>
#include "scn/IScene.hpp"
#include "scn/vc/Main.hpp"

namespace scn { namespace vc {
    class SceneVC : public IScene {
    public:
        struct Recipe {
            //NOTE: Merged into DefaultSwitchThreadCallback
            static Recipe Create(ContentKind kind);

            /* 0x0 */ ContentKind mKind;
        };

        SceneVC(const Recipe& rRecipe);

        /* 0x08 */ virtual const hel::common::RuntimeTypeInfo& GetRuntimeTypeInfo() const;
        /* 0x0C */ virtual ~SceneVC();
        /* 0x10 */ virtual void updateMain();
        /* 0x14 */ virtual void updateUseGPU();
        /* 0x18 */ virtual void updateDebug();
        /* 0x1C */ virtual void draw(const DrawReqInfo&);
        /* 0x20 */ virtual bool isSceneEnd() const;


    public:
        /* 0x4 */ hel::common::ScopedPtr<Main> mMain;
    };

}}

#endif
