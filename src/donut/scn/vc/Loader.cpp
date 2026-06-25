#pragma peephole off
#include "scn/vc/Loader.hpp"
#include "snd/SoundSystem.hpp"
#include "hid/HIDManager.hpp"
#include <revolution/VI.h>

namespace scn { namespace vc {
    namespace {
        const char* tFILENAME_TABLE[CONTENT_MAX] = {
            "vc/GB_kby1/GB_kby1.dol",
            "vc/FC_yume/FC_yume.dol",
            "vc/GB_kby2/GB_kby2.dol",
            "vc/SF_kby3/SF_kby3.dol",
            "vc/SF_sdx/SF_sdx.dol",
            "vc/64_k64/64_k64.dol",
        };
    }

    void Loader::load(ContentKind kind) {
        snd::shutdownSystem();
        hid::HIDManager::Instance->resetGCControllerAll();
        VISetBlack(TRUE);
        VIFlush();
        VIWaitForRetrace();
        OSExecl(tFILENAME_TABLE[kind], nullptr);
    }

    //NOTE: All functions below are code merged into others. Refer to the header for more details

    Loader::Loader() { }
}}
