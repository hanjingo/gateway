#ifndef GATEWAY_HPP
#define GATEWARY_HPP

#include "interface.hpp"

namespace gateway
{
    class GateWay{
    private:
        HttpHandlerI *http;
        StreamPlayerI *player;
        CacheMgrI *cache;
        RecordMgr *record;
    
    public:
        GateWay(){};
        ~GateWay(){};
    };
}

#endif