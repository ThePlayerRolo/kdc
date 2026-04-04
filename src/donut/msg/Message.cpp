#pragma peephole off
#include <donut/msg/Message.hpp>
#include <hel/common/FixedStringIN.hpp>
#include <hel/common/Traits.hpp>
#include <donut/app/Locale.hpp>

using msg::Message;

namespace {
    #define NUM_DIRS 7

    /*
        Message Directory Order Goes as Follows:
        1. Japanese Directory
        2. English Directory
        3. German Directory
        4. French Directory
        5. Spanish DIrectory
        6. Italian Directory
        7. Dutch Directory
    */

    const char* DIRS_US[NUM_DIRS] = {
        nullptr,
        "US_English",
        nullptr,
        "US_French",
        "US_Spanish",
        nullptr,
        nullptr,
    };

    const char* DIRS_EU[NUM_DIRS] = {
        nullptr,
        "EU_English",
        "EU_German",
        "EU_French",
        "EU_Spanish",
        "EU_Italian",
        "EU_Dutch",
    };

    const char* DIRS_JP[NUM_DIRS] = {
        "JP_Japanese",
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
    };
};

//https://decomp.me/scratch/vFaa1
Message::Message(const char* pFilename) {
    const char* msbt = ".msbt";
    char strCopy[80] = {0};
    hel::common::Traits<char>::Strncpy(strCopy, msbt, 80);
    const char* filePath = FilePath(pFilename);

    char* strCopy2;

    strCopy2  = hel::common::FixedStringIN<char, 80>::FromFormat("%s%s", filePath,
    strCopy).str();

    mFileAccessor = file::FileAccessor(strCopy2, false);
    mMessageInfo = LMS_InitMessage(mFileAccessor.block().mStartAddress);
}

Message::~Message() {
    LMS_CloseMessage(mMessageInfo);
    mMessageInfo = nullptr;
}

//https://decomp.me/scratch/GORYp
const char* Message::FilePath(const char* pFileName) {
    int language = app::Locale::GetLanguage();
    const char* regionDir = nullptr;
    int region = app::Locale::GetRegion();

    switch (region) {
        case 0:
            regionDir = DIRS_JP[language];
            break;
        case 1:
            regionDir = DIRS_US[language];
            break;
        case 2:
            regionDir = DIRS_EU[language];
            break;
    }
    return hel::common::FixedStringIN<char, 80>::FromFormat("msg/%s/%s", regionDir, pFileName).str();
}

const wchar_t* Message::text(const char* pTag) const {
    int index = LMS_GetTextIndexByLabel(mMessageInfo, pTag);
    if (index < 0 || LMS_GetTextNum(mMessageInfo) <= index) {
        return 0;
    }
    return LMS_GetText(mMessageInfo, index);
}
