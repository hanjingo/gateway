#pragma once

#include <interface.hpp>
#include <gate_config.hpp>

namespace gateway{

class CacheMgrV1 : CacheMgrI
{
public:
    CacheConfig &CacheCfg;
    IpfsConfig &IpfsCfg;
};

}