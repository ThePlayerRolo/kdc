#ifndef DONUT_SEQ_SEQUENCELVMAPROOT_HPP
#define DONUT_SEQ_SEQUENCELVMAPROOT_HPP

#include "scn/IScene.hpp"
#include "seq/ISequence.hpp"

/* clang-format off */

namespace seq {

class SequenceLvMapRoot
{
public:
    SequenceLvMapRoot();
    ~SequenceLvMapRoot();
    u32 nextAction() const;
    void createChildSequence() const;
    void onChildSequenceEnd();
    void createScene() const;
    void onSceneEnd(scn::IScene & scene);
    void setupForLeaveDoor();
    void resetContextHero(bool param_1);
    void onChildSequenceEndForLvMap(ISequence & sequence);
    void onChildsequenceEndForChallenge(ISequence & sequence);
    void GetRuntimeTypeInfo() const;
};

}

#endif
