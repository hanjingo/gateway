#pragma once

#include <memory>
#include <interface.hpp>
#include <gate_config.hpp>

namespace gateway
{
    // 网关
    class Gateway{
    private:
        std::unique_ptr<HttpServerI>   http;   // http服务器
        std::unique_ptr<StreamPlayerI> player; // 流媒体播放器
        std::unique_ptr<CacheMgrI>     cache;  // 缓存管理器
        std::unique_ptr<RecordMgrI>    record; // 记录管理器

    public:
        inline std::shared_ptr<HttpServerI> Http(){};
        inline std::shared_ptr<StreamPlayerI> Player(){};
        inline std::shared_ptr<CacheMgrI> Cache(){};
        inline std::shared_ptr<RecordMgrI> Record(){};
    
    public:
        Gateway(){};
        ~Gateway(){};

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
