#ifndef DONUT_SCN_VC_LOADER_HPP
#define DONUT_SCN_VC_LOADER_HPP

#include <types.h>

namespace scn { namespace vc {
    enum ContentKind {
        CONTENT_KBY1, // Kirby's Dreamland (Gameboy)
        CONTENT_YUME, // Kirby's Adventure (NES)
        CONTENT_KBY2, // Kirby's Dreamland 2 (Gameboy)
        CONTENT_KBY3, // Kirby's Dreamland 3 (SNES)
        CONTENT_SDX, // Kirby Super Star (SNES)
        CONTENT_K64, // Kirby 64 (N64)
        CONTENT_MAX,
    };

    class Loader {
    public:
        // NOTE: Is merged into DefaultSwitchThreadCallback
        Loader();

        void load(ContentKind kind);
    };
}}

#endif
