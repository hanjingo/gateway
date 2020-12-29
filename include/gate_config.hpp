#pragma once

#include <string>
#include <config.hpp>

namespace gateway{

class Config : conf::Config 
{
public:
    HttpConfig &Http;
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
