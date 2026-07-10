#pragma peephole off
#include <donut/util/CurveUtility.hpp>

namespace util {
    namespace CurveUtility {

        f32 square(f32 in) {
            return in * in;
        }

        f32 invSquare(f32 in) {
            return 1.0f - square(1.0f - in);
        }

    }
}
