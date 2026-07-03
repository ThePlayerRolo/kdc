#pragma peephole off
#include "font/FontKindUtil.hpp"

namespace font {
    namespace {
        struct FontContextEntry {
            /* 0x0 */ const char* mLangFolder;
            /* 0x4 */ const char* mName;
        };

        const FontContextEntry T_FONT_CONTEXT_TABLE[KIND_MAX] = {
            {"jp/", "CommonEB.brfnt" },
            {"jp/", "CommonEBFixed.brfnt" },
            {"jp/", "CommonEBOL.brfnt" },
            {"jp/", "CommonEBOLFixed.brfnt" },
            {"jp/", "Skip.brfnt" },
            {"jp/", "SkipOutline.brfnt" },
            {"jp/", "ExternalChar.brfnt" },
            {"jp/", "StaffCredits.brfnt" },
            {"jp/", "Arare.brfnt" },
        };

        const FontContextEntry t_context(FontKind kind) {
            // Needs this to match not inline on -O3,S which I think is what they used
            // It also makes sense since if there wasn't a debugging thing here why would they make this a function?
            // - ThePlayerRolo
            if (kind < 0 || kind > KIND_MAX) { }

            return T_FONT_CONTEXT_TABLE[kind];
        }
    }

    namespace FontKindUtil {
        hel::common::FixedString<80> FilePath(FontKind kind) {
            const FontContextEntry entry = t_context(kind);
            return hel::common::FixedString<80>::FromFormat("font/%s%s", entry.mLangFolder, entry.mName);
        }

        const char* Name(FontKind kind) {
            return t_context(kind).mName;
        }
    }
}
