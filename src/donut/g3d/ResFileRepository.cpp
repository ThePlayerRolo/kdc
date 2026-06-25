#pragma peephole off
#include "g3d/ResFileRepository.hpp"

namespace g3d {
    ResFileRepository::ResFileRepository()  : mRepo() { }
    ResFileRepository::~ResFileRepository() { }

    ResFileAccessor& ResFileRepository::get(const char* pName, bool param_2) {
        ResFileRepository::Node* node = find(pName);
        if (node != nullptr) return node->mFile.accessor();

        node = new Node(pName, param_2);

        //TODO: Add proper std::auto_ptr
    }

    ResFileRepository::Node* ResFileRepository::find(const char* pName) {
        for (int i = 0; i < mRepo.mSize; i++) {
            ResFileRepository::Node* node = mRepo.mArray[i];
            if (hel::common::Traits<char>::Strcmp(node->mFileName.str(), pName) != 0) {
                return node;
            }
        }

        return nullptr;
    }

    ResFileRepository::Node::Node(const char* pFileName, bool param_2)
        : mFileName(pFileName)
        , mFile(mFileName.str(), param_2)
    { }

    ResFileRepository::Node::~Node() { }
}
