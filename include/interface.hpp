#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <memory>

#include "file_info.hpp"
#include "../lib/error.hpp"

namespace gateway
{

    enum class HttpTyp : uint8_t {
        GET = 1,  // http GET
        POST = 2 // http POST
    };

    class MgrI {
        virtual std::shared_ptr<err::Error> Init() = 0;
        virtual std::shared_ptr<err::Error> Run() = 0;
        virtual void Close() = 0;
    };

    class HttpHandlerI {
    public:
        virtual std::shared_ptr<err::Error> Service() = 0;
        virtual std::shared_ptr<err::Error> SetInvoke(const HttpTyp typ, const std::string url, void (*func)()) = 0;
    };

    class StreamPlayerI {
        virtual std::shared_ptr<err::Error> Play() = 0;
    };

    class CacheMgrI : MgrI {
        virtual std::shared_ptr<err::Error> Save(const FileInfo& f) = 0;
        virtual std::shared_ptr<err::Error> SetInvoke(const char* typ, void (*func)()) = 0;
    };

    class RecordMgrI : MgrI {
        virtual std::shared_ptr<err::Error> Add(const FileInfo& f) = 0;
        virtual std::shared_ptr<err::Error> Get(FileInfo& f) = 0;
    };
}



#endif