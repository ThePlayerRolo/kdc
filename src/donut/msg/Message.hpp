#ifndef DONUT_MSG_PROJECT_HPP
#define DONUT_MSG_PROJECT_HPP

#include <donut/file/FileAccessor.hpp>
#include <libms/msgfile.h>

namespace msg {
    class Message {
    public:
        Message(const char* pFilename);
        ~Message();

        const wchar_t* text(const char* pTag) const;
        const char* FilePath(const char* pFileName);

    private:
        /* 0x00 */ file::FileAccessor mFileAccessor;
        /* 0x68 */ struct MsbtInfo* mMessageInfo;
    };
}

#endif
