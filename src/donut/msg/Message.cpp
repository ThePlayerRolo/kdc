#pragma peephole off
#include <donut/msg/Message.hpp>
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

//https://decomp.me/scratch/ngvuW
Message::Message(const char* pFilename) {
    hel::common::FixedString<80> strCopy(".msbt");
    hel::common::FixedString<80> strCopy2  = hel::common::FixedString<80>::FromFormat("%s%s", FilePath(pFilename).str(),
    strCopy.str());

    mFileAccessor = file::FileAccessor(strCopy2.str(), false);
    mMessageInfo = LMS_InitMessage(mFileAccessor.block().mStartAddress);
}

Message::~Message() {
    LMS_CloseMessage(mMessageInfo);
    mMessageInfo = nullptr;
}

//https://decomp.me/scratch/snpLJ
hel::common::FixedString<80> Message::FilePath(const char* pFileName) {
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
    return hel::common::FixedString<80>::FromFormat("msg/%s/%s", regionDir, pFileName);
}

const wchar_t* Message::text(const char* pTag) {
    int index = LMS_GetTextIndexByLabel(mMessageInfo, pTag);
    if (index < 0 || LMS_GetTextNum(mMessageInfo) <= index) {
        return 0;
    }
    return LMS_GetText(mMessageInfo, index);
}
