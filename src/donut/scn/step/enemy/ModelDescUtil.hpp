#ifndef DONUT_SCN_STEP_ENEMY_MODEL_DESC_UTIL_HPP
#define DONUT_SCN_STEP_ENEMY_MODEL_DESC_UTIL_HPP

#include "scn/step/chara/ModelDesc.hpp"
#include "gobj/G3DAnimDataReposDesc.hpp"
#include "gobj/ScriptDesc.hpp"
#include "gobj/AnimDesc.hpp"

namespace scn { namespace step { namespace enemy {

    namespace ModelDescUtil {

        void Set(chara::ModelDesc& rModel, gobj::AnimDesc& rAnimDesc, gobj::ScriptDesc& rScriptDesc, const char* pModelPath, const char* pModelName,
            u32 nodeNameSize, const char** pNodeNames,
            u32 animEntrySize, const gobj::G3DAnimDataReposDesc::Entry* pAnimEntries,
            u32 scriptEntrySize, const gobj::ScriptDesc::Entry* pScriptEntries);

        template < int T, int S >
        inline chara::ModelDesc& CreateTmpl(const char* pModelPath, const char* pModelName,
            u32 nodeNameSize, const char** pNodeNames,
            u32 animEntrySize, const gobj::G3DAnimDataReposDesc::Entry* pAnimEntries,
            u32 scriptEntrySize, const gobj::ScriptDesc::Entry* pScriptEntries)
        {
            static chara::ModelDesc desc;
            static gobj::AnimDesc animDesc;
            static gobj::ScriptDesc scriptDesc;

            Set(desc, animDesc, scriptDesc, pModelPath, pModelName, nodeNameSize, pNodeNames, animEntrySize, pAnimEntries, scriptEntrySize, pScriptEntries);
            return desc;
        }
    }
}}};

#endif
