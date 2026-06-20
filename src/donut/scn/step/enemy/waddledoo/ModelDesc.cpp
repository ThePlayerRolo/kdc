#pragma peephole off
#include "scn/step/enemy/waddledoo/ModelDesc.hpp"
#include "scn/step/enemy/ModelDescUtil.hpp"
#include "gobj/AnimScript.hpp"

namespace scn { namespace step { namespace enemy { namespace waddledoo {

    namespace {
        #define NODE_NAME_NORMAL_SIZE 11
        #define ANIM_ENTRIES_SIZE 22
        #define SCRIPT_ENTRIES_SIZE 21

        const char* T_NODE_NAMES_NORMAL[NODE_NAME_NORMAL_SIZE] = {
            "TopL",
            "CA4FaceJ",
            "BeamBaseJ",
            "Beam1J",
            "Beam2J",
            "Beam3J",
            "Beam4J",
            "RA3HandJ",
            "RA1ShoulderJ",
            "RHaveL",
            "CA4FaceJ",
        };

        ANIM_ENTRIES_START(ANIM_ENTRIES_SIZE)
            ANIM_ENTRY("Wait1",0)
            ANIM_ENTRY("Fall",0)
            ANIM_ENTRY("Landing",0)
            ANIM_ENTRY("Move",0)
            ANIM_ENTRY("Jump",0)
            ANIM_ENTRY("Damage",0)
            ANIM_ENTRY("DamageEtc",0)
            ANIM_ENTRY("Attack",0)
            ANIM_ENTRY("Jump",0) // why two?
            ANIM_ENTRY("JumpStart",0)
            ANIM_ENTRY("AttackStart",0)
            ANIM_ENTRY("AttackReserve",0)
            ANIM_ENTRY("ParasolDoo",0)
            ANIM_ENTRY("ParasolDooLanding",0)
            ANIM_ENTRY("ParasolDooOut",0)
            ANIM_ENTRY("HaveParasol",0)
            ANIM_ENTRY("ConnectionHavePose",0)
            ANIM_ENTRY("SwingFront",0)
            ANIM_ENTRY("SwingBack",0)
            ANIM_ENTRY("TurnFront",0)
            ANIM_ENTRY("TurnBack",0)
            ANIM_ENTRY("GoodbyeLoop",0)
        ANIM_ENTRIES_END

        SCRIPT_ENTRIES_START(SCRIPT_ENTRIES_SIZE)
            SCRIPT_ENTRY(gobj::AnimScript::PLAY_LOOP, 0, 4, 0, 0)
            SCRIPT_ENTRY(gobj::AnimScript::PLAY_LOOP, 1, 4, 0, 0)
            SCRIPT_ENTRY(gobj::AnimScript::PLAY_ONE_SHOT, 2, 2, 0, 0)
            SCRIPT_ENTRY(gobj::AnimScript::PLAY_LOOP, 3, 4, 0, 0)
            SCRIPT_ENTRY(gobj::AnimScript::PLAY_LOOP, 3, 4, 0, 0)
            SCRIPT_ENTRY(gobj::AnimScript::PLAY_ONE_SHOT, 5, 2, 0, 0)
            SCRIPT_ENTRY(gobj::AnimScript::PLAY_LOOP, 6, 2, 0, 0)
            SCRIPT_ENTRY("WaddleDoo.AnimScript.Attack.Exec", 0, 0, 0, 0)
            SCRIPT_ENTRY(gobj::AnimScript::PLAY_ONE_SHOT, 8, 2, 0, 0)
            SCRIPT_ENTRY(gobj::AnimScript::PLAY_ONE_SHOT, 9, 2, 0, 0)
            SCRIPT_ENTRY(gobj::AnimScript::PLAY_LOOP, 12, 36, 0, 0)
            SCRIPT_ENTRY(gobj::AnimScript::PLAY_ONE_SHOT, 13, 4, 0, 0)
            SCRIPT_ENTRY(gobj::AnimScript::PLAY_ONE_SHOT, 14, 4, 0, 0)
            SCRIPT_ENTRY(gobj::AnimScript::PLAY_ONE_SHOT, 15, 4, 0, 0)
            SCRIPT_ENTRY(gobj::AnimScript::PLAY_ONE_SHOT, 16, 0, 0, 0)
            SCRIPT_ENTRY(gobj::AnimScript::PLAY_LOOP, 17, 2, 0, 0)
            SCRIPT_ENTRY(gobj::AnimScript::PLAY_LOOP, 18, 2, 0, 0)
            SCRIPT_ENTRY(gobj::AnimScript::PLAY_ONE_SHOT, 19, 2, 0, 0)
            SCRIPT_ENTRY(gobj::AnimScript::PLAY_ONE_SHOT, 20, 2, 0, 0)
            SCRIPT_ENTRY("WaddleDoo.AnimScript.SuperAppear.Exec", 0, 0, 0, 0)
            SCRIPT_ENTRY(gobj::AnimScript::PLAY_LOOP, 21, 8, 0, 0)
        SCRIPT_ENTRIES_END
    }

    namespace ModelDesc {
        //https://decomp.me/scratch/8ptq3
        chara::ModelDesc& CreateNormal() {
            return ModelDescUtil::CreateTmpl<16, 0>("step/chara/enemy/Doo", "Waddledoo",
                NODE_NAME_NORMAL_SIZE, T_NODE_NAMES_NORMAL,
                ANIM_ENTRIES_SIZE, T_ANIM_ENTRIES, SCRIPT_ENTRIES_SIZE, T_SCRIPT_ENTRIES);
        }
    }

}}}}
