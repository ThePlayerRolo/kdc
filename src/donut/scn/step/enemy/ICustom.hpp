#ifndef DONUT_SCN_STEP_ENEMY_INTERFACE_CUSTOM_HPP
#define DONUT_SCN_STEP_ENEMY_INTERFACE_CUSTOM_HPP

namespace scn { namespace step {
    namespace enemy {
    class Enemy;

    class ICustom {
    public:
        virtual void GetRuntimeTypeInfo() const { }
        //NOTE: Merged into IScene::~IScene()
        virtual ~ICustom();
    };

}}};

#endif
