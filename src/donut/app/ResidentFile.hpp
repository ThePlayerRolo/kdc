#ifndef DONUT_APP_RESIDENTFILE_HPP
#define DONUT_APP_RESIDENTFILE_HPP

#include <types.h>

namespace app {

class ResidentFile {
public:
    ResidentFile();
    ~ResidentFile();

    void startIfNecessary();
    void waitToFinish();
private:
    STRUCT_FILL(0x3D0);
};

}

#endif
