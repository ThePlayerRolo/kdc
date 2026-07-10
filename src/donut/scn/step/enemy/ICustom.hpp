#ifndef DONUT_SCN_STEP_ENEMY_INTERFACE_CUSTOM_HPP
#define DONUT_SCN_STEP_ENEMY_INTERFACE_CUSTOM_HPP

namespace scn { namespace step {
    namespace enemy {
    class Enemy;

    class ICustom {
    public:
        /* 0x08 */ virtual void GetRuntimeTypeInfo() const { }
        //NOTE: Merged into IScene::~IScene()
        /* 0x0C */ virtual ~ICustom();
    };

}}};

#endif
