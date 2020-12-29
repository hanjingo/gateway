#pragma once

#include<interface.hpp>
#include<gate_config.hpp>

namespace gateway{

class RecordMgrV1 : RecordMgrI
{
public:
    PgConfig &PgCfg;
    RdsConfig &RdsCfg;
};

}