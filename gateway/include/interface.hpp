#pragma once

#include <memory>
#include "file_info.hpp"
#include "lib/utils/error.hpp"

namespace gateway
{
    enum class HttpTyp : uint8_t {
        GET = 1,  // http GET
        POST = 2 // http POST
    };

    class MgrI {
    public:
        virtual void Init(err::Error &e) = 0;
        virtual void Run(err::Error &e) = 0;
        virtual void Close() = 0;
    };

    class HttpServerI {
    public:
        virtual void Service(err::Error &e) = 0;
        virtual void SetInvoke(err::Error &e, const HttpTyp typ, const std::string &url, void (*func)()) = 0;
    };

    class StreamPlayerI {
    public:
        virtual void Play(err::Error &e) = 0;
    };

    class CacheMgrI : public MgrI {
    public:
        virtual void Save(err::Error &e, const FileInfo &f) = 0;
        virtual void SetInvoke(err::Error &e, const std::string &typ, void (*func)()) = 0;
    };

    class RecordMgrI : public MgrI {
    public:
        virtual void Add(err::Error &e, const FileInfo &f) = 0;
        virtual void Get(err::Error &e, FileInfo &f) = 0;
    };
}
