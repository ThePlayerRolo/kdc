#ifndef DONUT_SCN_VC_MAIN_HPP
#define DONUT_SCN_VC_MAIN_HPP

#include "scn/DrawReqInfo.hpp"
#include "scn/vc/Loader.hpp"

namespace scn { namespace vc {
    class Main {
    public:
        Main(ContentKind kind);

        //NOTE: Merged into DefaultSwitchThreadCallback
        void updateUseGPU();
        //NOTE: Merged into DefaultSwitchThreadCallback
        void updateMain();
        //NOTE: Merged into DefaultSwitchThreadCallback
        void updateDebug();
        //NOTE: Merged into DefaultSwitchThreadCallback
        void draw(const DrawReqInfo&);

        //NOTE: Merged into nururi::Nururi::isValid() const
        bool IsEnd() const;
    public:
        /* 0x0 */ Loader mLoader;
        /* 0x4 */ ContentKind mKind;
        /* 0x8 */ bool mIsEnd;
    };

}}

#endif
