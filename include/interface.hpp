#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "file_info.hpp"
#include "error.hpp"

namespace gateway
{
    using namespace err;
    using namespace file;

    enum class HttpTyp : uint8_t {
        GET = 1,  // http GET
        POST = 2 // http POST
    };

    class Mgr {
        virtual const Error &Init() = 0;
        virtual const Error &Run() = 0;
        virtual void Close() = 0;
    };

    class HttpHandlerI {
    public:
        virtual const Error &Service() = 0;
        virtual Error &SetInvoke(const HttpTyp typ, const std::string url, void (*func)()) = 0;
    };

    class StreamPlayerI {
        virtual Error &Play() = 0;
    };

    class CacheMgrI : Mgr {
        virtual Error &Save(const FileInfo& f) = 0;
        virtual Error &SetInvoke(const char* typ, void (*func)()) = 0;
    };

    class RecordMgr : Mgr {
        virtual Error &Add(const FileInfo& f) = 0;
        virtual Error &Get(FileInfo& f) = 0;
    };
}



#endif