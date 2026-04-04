#ifndef DONUT_APP_LOCALE_HPP
#define DONUT_APP_LOCALE_HPP

namespace app {
class Locale {
public:
    static const char* FilePostfix();

    //NOTE: Merged into nw4r::ut::DvdFileStream::CanCancel() const
    static int GetRegion();
    //NOTE Merged into nw4r::ut::DvdFileStream::CanCancel() const
    static int GetLanguage();

};
}

#endif
