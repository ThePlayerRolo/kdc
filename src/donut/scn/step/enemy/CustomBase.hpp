#ifndef DONUT_SCN_STEP_ENEMY_CUSTOM_BASE_HPP
#define DONUT_SCN_STEP_ENEMY_CUSTOM_BASE_HPP

#include <types.h>
#include "scn/step/enemy/Enemy.hpp"
#include "scn/step/enemy/ICustom.hpp"

namespace scn { namespace step {
    namespace enemy {
    class Enemy;

    class CustomBase : public ICustom {
    public:
        CustomBase(Enemy& rObj);

        /* 0x08 */ virtual void GetRuntimeTypeInfo() const;
        /* 0x0C */ virtual ~CustomBase();
        //NOTE: Replaced by a branch to __wpadNoAlloc
        /* 0x10 */ virtual bool onInit();
        //NOTE: Replaced by a branch to __wpadNoAlloc
        /* 0x14 */ virtual bool onHitPointIsZero();
        //NOTE: Replaced by a branch to __wpadNoAlloc
        /* 0x18 */ virtual bool onVacuumReceive();
        //NOTE: Replaced by a branch to __wpadNoAlloc
        /* 0x1C */ virtual bool onVacuumResist();
        //NOTE: Replaced by a branch to __wpadNoAlloc
        /* 0x20 */ virtual bool onDamaged();
        /* 0x24 */ virtual bool onInWater();
        //NOTE: Replaced by a branch to __wpadNoAlloc
        /* 0x28 */ virtual bool onOutWater();
        //NOTE: Replaced by a branch to __wpadNoAlloc
        /* 0x2C */ virtual bool onRecover();
        /* 0x30 */ virtual void onCaptured();
        /* 0x34 */ virtual void onDead();
        /* 0x38 */ virtual void onProcFixPos();
        //NOTE: Replaced by a branch to __wpadNoAlloc
        /* 0x3C */ virtual bool reqCustomDeadEffect();
        /* 0x40 */ virtual void setupSuperEnemyEffect();

        // Yes, both do exist according to the map file and they do the same exact thing :)
        // NOTE: Is merged into GetZeroBufferAddress__Q44nw4r3snd6detail9AxManagerFv
        Enemy& obj() const;
        //NOTE: Is merged into GetZeroBufferAddress__Q44nw4r3snd6detail9AxManagerFv
        Enemy& obj();
    public:
        /* 0x4 */ Enemy& mObj;
    };

}}};

#endif
