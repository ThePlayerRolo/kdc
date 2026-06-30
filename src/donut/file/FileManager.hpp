#ifndef DONUT_FILE_FILEMANAGER_HPP
#define DONUT_FILE_FILEMANAGER_HPP

#include <donut/file/FileTree.hpp>

namespace file {

// NOTE that treeRoot being a blr helps prove that this inherits FileTree (Returning this for it generates a blr only)
class FileManager : FileTree {
public:
    FileManager();
    ~FileManager();

    void clearFiles();
    void clearFilesIfEnable();

    //NOTE: Merged into DefaultSwitchThreadCallback
    FileTree* treeRoot() const;

    void disableClearInc();
    void disableClearDec();

private:
    /* 0x40 */ s32 mDisableClear;
};

}

#endif
