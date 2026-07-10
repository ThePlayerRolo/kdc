#ifndef DONUT_HID_DPD_HPP
#define DONUT_HID_DPD_HPP

#include <hel/common/PrivateSingleton.hpp>

namespace hid {
    class LibInitializer : public hel::common::PrivateSingleton<LibInitializer> {
    public:
        LibInitializer();
        ~LibInitializer();
    };
}
#endif
