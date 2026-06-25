#pragma peephole off
#include "g3d/ResFileRepository.hpp"

namespace g3d {
    // https://decomp.me/scratch/hkUWx
    ResFileRepository::ResFileRepository()  : mRepo() { }
    ResFileRepository::~ResFileRepository() { }

    // https://decomp.me/scratch/FLqtV
    ResFileAccessor& ResFileRepository::get(const char* pName, bool param_2) {
        ResFileRepository::Node* node = find(pName);
        if (node != nullptr) return node->mFile.accessor();

        node = new Node(pName, param_2);

        //TODO: Add proper std::auto_ptr
    }

    // https://decomp.me/scratch/L9iif
    ResFileRepository::Node* ResFileRepository::find(const char* pName) {
        for (int i = 0; i < mRepo.mSize; i++) {
            ResFileRepository::Node* node = mRepo.mArray[i];
            if (hel::common::Traits<char>::Strcmp(node->mFileName.str(), pName) != 0) {
                return node;
            }
        }

        return nullptr;
    }

    // https://decomp.me/scratch/aqnx5
    ResFileRepository::Node::Node(const char* pFileName, bool param_2)
        : mFileName(pFileName)
        , mFile(mFileName.str(), param_2)
    { }

    ResFileRepository::Node::~Node() { }
}
