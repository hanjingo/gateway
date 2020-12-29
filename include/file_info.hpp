#pragma once

#include <chrono>
#include <memory>
#include <error.hpp>

namespace gateway
{
    // 文件状态
    enum class FileStat : uint8_t
    {
        Untracked = 0,  // 未追踪
        Tracked = 1,    // 已追踪
        Pulling = 2,    // 正在拉取
        Pulled = 3,     // 已拉取
        PullFail = 4,   // 拉取失败
        Expired = 5,    // 已过期
        Deleting = 6,   // 正在删除
        Deleted = 7     // 已删除
    };

    // 文件
    class FileInfo{
    public:
        char*                                 Hash;         // 文件hash
        FileStat                              Status;       // 文件状态
        std::chrono::system_clock::time_point CreateTime;   // 文件创建时间
        char*                                 FilePathName; // 文件当前路径

    public:
        inline void SetStat(const FileStat stat){};
        inline FileStat GetStat(){};

        void GetPg(err::Error &e);
        void SetPg(err::Error &e);
        void GetRds(err::Error &e);
        void SetRds(err::Error &e);
    };
}
