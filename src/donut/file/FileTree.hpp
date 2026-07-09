#ifndef DONUT_FILE_FILETREE_HPP
#define DONUT_FILE_FILETREE_HPP

#include "mem/HeapCompaction.hpp"

namespace file {
    class IFileInitializer;
    class FileLoader;

    class FileTree {
    public:
        FileTree();
        FileTree(mem::IAllocator&, mem::IAllocator&, u32, u32);

        ~FileTree();

        FileLoader* findFile(const char* pFilePath) const;
        FileLoader* addFile(const char* pFilePath, const IFileInitializer* pInitializer);
        void clearFiles();
        void setCompactionHeap(mem::HeapCompaction&);

    private:
        STRUCT_FILL(0x40);
    };

}

#endif
