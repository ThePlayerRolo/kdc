#ifndef DONUT_UTIL_CHARACTER_ENCODE_UTIL_HPP
#define DONUT_UTIL_CHARACTER_ENCODE_UTIL_HPP

#include <types.h>

namespace util {
    namespace CharacterEncodeUtil {
        void UTF8ToUTF16(wchar_t*, u32, const char*);
        bool UTF8ToUTF16(wchar_t*, u32, const char*, u32);
    };
}

#endif
