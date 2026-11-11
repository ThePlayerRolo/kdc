#include "g3d/ResAnmAutoReq.hpp"

namespace g3d {
    ResAnmAutoReq::ResAnmAutoReq() : mData(nullptr) { }
    ResAnmAutoReq::ResAnmAutoReq(const void* pData) : mData((const xdata::XData*)pData) { }

    bool ResAnmAutoReq::isValid() const {
        return mData != nullptr;
    }

    const xdata::XData* ResAnmAutoReq::data() const {
        return mData;
    }
}
