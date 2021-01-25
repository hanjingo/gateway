#pragma once

#include <memory>
#include "interface.hpp"
#include "config.hpp"
#include "cache_mgr_v1.hpp"
#include "record_mgr_v1.hpp"
#include "stream_player_v1.hpp"
#include "http_server_v1.hpp"

namespace gateway
{
    // 网关
    class Gateway{
    private:
        std::shared_ptr<HttpServerI>   _http;   // http服务器
        std::shared_ptr<StreamPlayerI> _player; // 流媒体播放器
        std::shared_ptr<CacheMgrI>     _cache;  // 缓存管理器
        std::shared_ptr<RecordMgrI>    _record; // 记录管理器

    public:
        inline std::shared_ptr<HttpServerI> Http(){ return _http; };
        inline std::shared_ptr<StreamPlayerI> Player(){ return _player; };
        inline std::shared_ptr<CacheMgrI> Cache(){ return _cache; };
        inline std::shared_ptr<RecordMgrI> Record(){ return _record; };
    
    public:
        Gateway()
        {
            _http = std::shared_ptr<HttpServerI>(new HttpServerV1());
            _player = std::shared_ptr<StreamPlayerI>(new StreamPlayerV1());
            _cache = std::shared_ptr<CacheMgrI>(new CacheMgrV1());
            _record = std::shared_ptr<RecordMgrI>(new RecordMgrV1());
        }
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
