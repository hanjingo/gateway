#pragma once

#include <memory>
#include <interface.hpp>
#include <gate_config.hpp>

namespace gateway
{
    class HttpServerV1 : HttpServerI {
    private:
        HttpConfig &HttpCfg;
        bool bRun;

    public:
    
    };
}