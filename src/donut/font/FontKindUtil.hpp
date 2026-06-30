#ifndef DONUT_FONT_FONT_KIND_UTIL_HPP
#define DONUT_FONT_FONT_KIND_UTIL_HPP

#include <hel/common/FixedString.hpp>

namespace font {
    enum FontKind {
        COMMON_EB,
        COMMON_EB_FIXED,
        COMMON_EB_OL,
        COMMON_EB_OL_FIXED,
        SKIP,
        SKIP_OUTLINE,
        EXTERNAL_CHAR,
        STAFF_CREDITS,
        ARARE,
        KIND_MAX,
    };

    namespace FontKindUtil {
        hel::common::FixedString<80> FilePath(FontKind kind);
        const char* Name(FontKind kind);
    }
}

#endif
