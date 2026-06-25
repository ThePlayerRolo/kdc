#include "app/Locale.hpp"

namespace app {

namespace {
    const char* const T_POSTS_US[] = {
        "US_JPN",
        "US_ENG",
        "US_GER",
        "US_FRA",
        "US_SPA",
        "US_ITA",
        "US_NED"
    };
}

const char* Locale::FilePostfix() {
    return T_POSTS_US[1];
}

//NOTE: All functions below are code merged into others. Refer to the header for more details

int GetRegion() {
    return 1;
}

int GetLanguage() {
    return 1;
}
}
