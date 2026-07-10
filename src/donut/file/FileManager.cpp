#pragma peephole off
#include "file/FileManager.hpp"
#include "mem/Memory.hpp"

namespace file {
    FileManager::FileManager()
        : FileTree(mem::Memory::Instance->mem1FixHeap(), mem::Memory::Instance->externalHeap().m_4, 512, 16)
        , mDisableClear(0)
    {
        setCompactionHeap(mem::Memory::Instance->externalHeap());
    }

    void FileManager::disableClearInc() {
        mDisableClear++;
    }

    void FileManager::disableClearDec() {
        mDisableClear--;
    }

    void FileManager::clearFiles() {
        FileTree::clearFiles();
    }

    void FileManager::clearFilesIfEnable() {
        if (mDisableClear == 0)
            FileTree::clearFiles();
    }

    //NOTE: All functions below are code merged into others. Refer to the header for more details

    FileTree* FileManager::treeRoot() const { return (FileTree*)this; }
}
