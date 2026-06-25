#pragma peephole off
#include "scn/vc/SceneVC.hpp"

HEL_RTTI_IMPL_PARENT(SceneVC, scn::IScene)

namespace scn { namespace vc {

    // https://decomp.me/scratch/Yg0lx
    SceneVC::SceneVC(const Recipe& rRecipe) : mMain(nullptr) {
        Main* main  = new Main(rRecipe.mKind);
        hel::common::ScopedPtr<Main> mainPtr(main);
        mMain = mainPtr;
    }

    void SceneVC::updateUseGPU() {
        mMain->updateUseGPU();
    }
    void SceneVC::updateMain() {
        mMain->updateMain();
    }
    void SceneVC::updateDebug() {
        mMain->updateDebug();
    }

    void SceneVC::draw(const DrawReqInfo& rDrawInfo) {
        mMain->draw(rDrawInfo);
    }

    bool SceneVC::isSceneEnd() const {
        return mMain->IsEnd();
    }

    const hel::common::RuntimeTypeInfo& SceneVC::GetRuntimeTypeInfo() const {
        return hel::common::RuntimeTypeInfoImpl<SceneVC>();
    }

    SceneVC::~SceneVC() { }
}}
