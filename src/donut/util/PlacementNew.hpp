#ifndef DONUT_UTIL_PLACEMENTNEW_HPP
#define DONUT_UTIL_PLACEMENTNEW_HPP

namespace util {
    template <typename T>
    class PlacementNew {
    public:
        ~PlacementNew();

        void destruct();
    private:
        T* ptr;
    };
}

#endif
