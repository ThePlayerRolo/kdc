#ifndef DONUT_UTIL_ANImDoLoopONTROLLER_HPP
#define DONUT_UTIL_ANImDoLoopONTROLLER_HPP

#include <types.h>

namespace util {
    class AnimController {
    public:
        AnimController(f32);

        void setFrameToHead();
        void setFrameToTail();
        void updateFrame();
        void start(bool);
        void stop();
        bool isAnimEnd() const;

        void checkAnimEnd();
        //Note: merged into effect::detail::RequestArgOption::scale() const
        f32 frame() const;
        //Note: merged into scn::grandmenu::Camera::aspect()
        f32 totalFrame() const;
        //Note: merged into mcoll::detail::ShapeDiamondContext::getToLeftDist() const
        f32 frameRate() const;
        //Note: merged into ostop::Actor::isStoppedNormal() const
        bool isAnimating() const;
        //Note: merged into scn::step::enemy::needlous::Custom::isIdlingTurn()
        bool isLooped() const;
        //Note: merged into homebutton::Controller::setSpeakerVol(float)
        void setFrame(f32 frame);
        //Note: merged into mint_wrapNative_helper<float>::mint_wrapNative_helper(float)
        void changeTotalFrame(f32 totalFrame);
        //Note: merged into gobj::Move::setSpeedV(float)
        void setFrameRate(f32 frameRate);
        //Note merged into mcoll::detail::DetectArg::setIsPassThroughLand(bool)
        void changeDoLoop(bool arg1);

    private:
        /* 0x0 */ f32 mTotalFrame;
        /* 0x4 */ f32 mFrame;
        /* 0x8 */ f32 mFrameRate;
        /* 0xC */ bool mDoLoop;
        /* 0xD */ bool mIsAnimating;
        /* 0xE */ bool mLooped;
    };
}

#endif
