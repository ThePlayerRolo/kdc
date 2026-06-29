#ifndef RVL_SDK_WUD_HID_HOST_H
#define RVL_SDK_WUD_HID_HOST_H
#include <types.h>

//If you include all of BTE scratches take FOREVER (and could crash your editor lol)
#include <revolution/BTE/bta/include/bta_hh_api.h>
#ifdef __cplusplus
extern "C" {
#endif

void WUDHidHostCallback(tBTA_HH_EVT event, tBTA_HH* pData);

#ifdef __cplusplus
}
#endif
#endif
