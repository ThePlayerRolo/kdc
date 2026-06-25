#ifndef DONUT_G3D_RES_FILE_REPOSITORY_HPP
#define DONUT_G3D_RES_FILE_REPOSITORY_HPP

#include "g3d/ResFile.hpp"
#include <hel/common/FixedString.hpp>
#include <hel/common/AutoDeleteArray.hpp>

#define RES_FILE_REPOSITORY_SIZE 128

namespace g3d {
    class ResFileRepository {
    public:
        class Node {
        public:
            Node(const char* pFileName, bool);
            ~Node();
        public:
            /* 0x00 */ hel::common::FixedString<80> mFileName;
            /* 0x50 */ ResFile mFile;
        };

    public:
        ResFileRepository();

        ~ResFileRepository();

        Node* find(const char* pName);
        ResFileAccessor& get(const char* pName, bool);
    public:
        /* 0x0 */ hel::common::AutoDeleteArray<Node, RES_FILE_REPOSITORY_SIZE> mRepo;
    };
}

#endif
