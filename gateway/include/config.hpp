#pragma once

#include <string>
#include <memory>
#include "lib/utils/error.hpp"

namespace gateway{

class HttpConfig;
class CacheConfig;
class PgConfig;
class RdsConfig;
class IpfsConfig;

class Config
{
private:
    static std::shared_ptr<Config> _instance; // 单例
    bool bLoad;                               // 是否加载过

public:
    std::shared_ptr<HttpConfig>     Http;
    std::shared_ptr<CacheConfig>    Cache;
    std::shared_ptr<PgConfig>       Pg;
    std::shared_ptr<RdsConfig>      Rds;
    std::shared_ptr<IpfsConfig>     Ipfs;

public:
    static std::shared_ptr<Config> Instance()
    {
        if (_instance == nullptr) { 
            _instance = std::make_shared<Config>(); 
        }
        return _instance;
    };

    Config() {};
    ~Config() {};

    // 加载配置，只能调用一次
    void Load(err::Error &e, const std::string &path);
    
    // 重新加载配置，可以调用多次
    void Reload(err::Error &e, const std::string &path);
};

class HttpConfig
{
public:
    std::string Addr;
    std::string StaticSourcePath;
};

class CacheConfig
{
public:
    uint32_t FileExpireDur;
    std::string Path;
};

class PgConfig
{
public:
    std::string Host;
    uint32_t Port;
    std::string User;
    std::string Passwd;
    std::string DataBase;
};

class RdsConfig
{
public:
    std::string Host;
    uint32_t Port;
};

class IpfsConfig
{
public:
    std::string Host;
    uint32_t Port;
    uint32_t PullExpireDur;
};

}
