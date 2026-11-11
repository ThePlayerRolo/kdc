#ifndef DONUT_G3D_COLOR_ANIM_FLASH_HPP
#define DONUT_G3D_COLOR_ANIM_FLASH_HPP

#include <revolution/GX.h>

namespace g3d {
    class ColorAnimTevManager;
    class MaterialAccessor;
    class ColorAnimMaterialTarget;

    enum ColorAnimFlashOp {
        COLOR_ANIM_FLASH_OP_0,
        COLOR_ANIM_FLASH_OP_1,
        COLOR_ANIM_FLASH_OP_2,
    };

    class ColorAnimFlash {
    public:
        ColorAnimFlash();

        static ColorAnimMaterialTarget CreateMaterialTarget(ColorAnimTevManager& rManager);

        void setColor(const GXColor& color);
        void reflectToMaterial(const MaterialAccessor& rMatAccessor, const ColorAnimMaterialTarget& rTarget) const;
        // NOTE: Is merged into homebutton::gui::EventHandler::setManager(homebutton::gui::Manager*)
        void setOperation(ColorAnimFlashOp operation);
    public:
        /* 0x0 */ GXColor mColor;
        /* 0x4 */ ColorAnimFlashOp mOperation;
    };

}

#endif
