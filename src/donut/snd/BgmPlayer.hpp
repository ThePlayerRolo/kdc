#ifndef DONUT_SND_BGM_PLAYER_HPP
#define DONUT_SND_BGM_PLAYER_HPP

#include <types.h>

namespace nw4r {
    namespace snd {
        class DvdSoundArchive;
        class SoundArchivePlayer;
    };
};

namespace snd {
    class BgmPlayer {
    public:
        BgmPlayer(nw4r::snd::DvdSoundArchive& rArchive, nw4r::snd::SoundArchivePlayer& rPlayer);
        ~BgmPlayer();

        void start(u32);
        void startWithSamplePos(u32, u32);
        void startWithSamplePos(u32, u32, int);
        void stop();
        void stop(int);
        void currentSamplePos();
        void setVolume(f32);
        void pauseForBGMStopMenuOpened();
        void resumeForBGMStopMenuClosed();
        void onSoftReset();
        void volumeFadeForPauseMenuOpened(bool);
        void volumeFadeForPauseMenuClosed();
        void volumeFade(f32, int);

        //Note: merged into nw4hbm::lyt::Pane::GetParent() const
        void playingSoundID() const;
        //Note: merged into util::ObjListNode<g3d::Model, util::ObjListDummyType>::isLink() const
        bool isPlaying() const;
        //note merged into this classes stop(int)
        void stopForResetOrPowerOff(int);

        /* 0x0 */ nw4r::snd::DvdSoundArchive* mArchive;
        /* 0x4 */ nw4r::snd::SoundArchivePlayer* mPlayer;
        /* 0x8 */ s32 m_8;
        /* 0xC */ s32 m_C;
        /* 0x10 */ s32 m_10;
    };
}

#endif
