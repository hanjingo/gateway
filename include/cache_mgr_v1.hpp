#pragma once

#include <interface.hpp>
#include <config.hpp>
#include <file_info.hpp>
#include <chrono>

namespace gateway{
using duration = std::chrono::system_clock::duration;

class CacheMgrV1 : public CacheMgrI
{
public:
    duration FileExpireDur; // 文件过期时长
    std::string CachePath;
    std::string IpfsHost;
    uint32_t IpfsPort;
    duration IpfsPullExpireDur;

    CacheMgrV1(const IpfsConfig &ipfs, const CacheConfig &cache){
        // todo
    }
    ~CacheMgrV1(){}

    void Init(err::Error &e);
    void Run(err::Error &e);
    void Close();
    void Save(err::Error &e, const FileInfo& f);
    void SetInvoke(err::Error &e, const std::string &typ, void (*func)());
};

}