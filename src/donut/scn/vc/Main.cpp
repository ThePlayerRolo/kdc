#pragma peephole off
#include "scn/vc/Main.hpp"

namespace scn { namespace vc {

    Main::Main(ContentKind kind)
    : mLoader()
    , mKind(kind)
    , mIsEnd(false)
    {
        mLoader.load(mKind);
        mIsEnd = true;
    }

    void Main::updateUseGPU() { }
    void Main::updateMain() { }
    void Main::updateDebug() { }
    void Main::draw(const DrawReqInfo&) {}

    bool Main::IsEnd() const { return mIsEnd; }
}}
