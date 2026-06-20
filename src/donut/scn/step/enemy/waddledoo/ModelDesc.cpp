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
            ANIM_ENTRY("Wait1",false)
            ANIM_ENTRY("Fall",false)
            ANIM_ENTRY("Landing",false)
            ANIM_ENTRY("Move",false)
            ANIM_ENTRY("Jump",false)
            ANIM_ENTRY("Damage",false)
            ANIM_ENTRY("DamageEtc",false)
            ANIM_ENTRY("Attack",false)
            ANIM_ENTRY("Jump",false) // why two?
            ANIM_ENTRY("JumpStart",false)
            ANIM_ENTRY("AttackStart",false)
            ANIM_ENTRY("AttackReserve",false)
            ANIM_ENTRY("ParasolDoo",false)
            ANIM_ENTRY("ParasolDooLanding",false)
            ANIM_ENTRY("ParasolDooOut",false)
            ANIM_ENTRY("HaveParasol",false)
            ANIM_ENTRY("ConnectionHavePose",false)
            ANIM_ENTRY("SwingFront",false)
            ANIM_ENTRY("SwingBack",false)
            ANIM_ENTRY("TurnFront",false)
            ANIM_ENTRY("TurnBack",false)
            ANIM_ENTRY("GoodbyeLoop",false)
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
