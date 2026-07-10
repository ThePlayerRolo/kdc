#pragma peephole off
#include <string.h>
#include <revolution/ENC.h>
#include <donut/util/CharacterEncodeUtil.hpp>

namespace util {
    namespace CharacterEncodeUtil {
        void UTF8ToUTF16(wchar_t* arg1, u32 arg2, const char* arg3) {
            UTF8ToUTF16(arg1, arg2, arg3, strlen(arg3));
        }

        //https://decomp.me/scratch/25sGg
        bool UTF8ToUTF16(wchar_t* arg1, u32 arg2, const char* arg3, u32 arg4) {

            s32 local_18;
            s32 local_14 = arg2;

            ENCResult result = ENCConvertStringUtf8ToUtf16((u16 *)arg1, (s32 *)&arg2, (const u8*)arg3, (s32 *)&arg4);
            if (result != ENC_OK) {
                return false;
            }
            local_18 = local_14 - 1;
            s32 finalIndex = local_18;
            if (local_18 > local_14) {
                finalIndex = local_14;
            }
            arg1[finalIndex] = 0;

            return true;
        }
    };
}
