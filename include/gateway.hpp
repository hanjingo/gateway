#ifndef GATEWAY_HPP
#define GATEWARY_HPP

#include <memory>
#include "interface.hpp"
#include "gateway_config.hpp"

namespace gateway
{
    // 网关
    class GateWay{
    private:
        std::unique_ptr<GatewayConfig> conf;   // 配置
        std::unique_ptr<HttpHandlerI>  http;   // http服务器
        std::unique_ptr<StreamPlayerI> player; // 流媒体播放器
        std::unique_ptr<CacheMgrI>     cache;  // 缓存管理器
        std::unique_ptr<RecordMgrI>    record; // 记录管理器
    
    public:
        GateWay(){};
        ~GateWay(){};

        std::shared_ptr<HttpHandlerI> Http();
        std::shared_ptr<StreamPlayerI> Player();
        std::shared_ptr<CacheMgrI> Cache();
        std::shared_ptr<RecordMgrI> Record();

        void Init();
        void Run();
        void Shutdown();

    private:
        void listenSignal();
        void initHttpHandler();
        void initPlayer();
        void initCacheMgr();
        void initRecordMgr();
    };
}

#endif