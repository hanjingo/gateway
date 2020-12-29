#ifndef FILE_INFO_HPP
#define FILE_INFO_HPP

#include <chrono>

namespace file
{
    enum class FileStat : uint8_t
    {
        Untracked = 0,
        Tracked = 1,
        Pulling = 2,
        Pulled = 3,
        PullFail = 4,
        Expired = 5,
        Deleting = 6,
        Deleted = 7
    };

    class FileInfo{
    public:
        char* Hash;                                        // 文件hash
        FileStat Status;                                   // 文件状态
        std::chrono::system_clock::time_point CreateTime;  // 文件创建时间
    };
}

#endif