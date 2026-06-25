#ifndef HEL_FIXED_STRING_HPP
#define HEL_FIXED_STRING_HPP

#include <hel/common/FixedStringIN.hpp>
#include <hel/common/Traits.hpp>

namespace hel {
namespace common {

template <size_t S>
class FixedString : public FixedStringIN<char, S> {
public:
    FixedString();

    FixedString(const char* pString)
        : FixedStringIN()
    {
        Traits<char>::Strncpy(mString, pString, S);
    }

    inline char* str() const {
        return (char*)mString;
    }

    void operator=(const FixedString& rOther);
};

} // common
} // hel

#endif
