#pragma once

#include <memory>
#include "interface.hpp"
#include "config.hpp"

namespace gateway
{
    class HttpServerV1 : public HttpServerI {
    private:
        bool bRun;

    public:
        HttpServerV1();
        ~HttpServerV1();

        void Service(err::Error &e);
        void SetInvoke(err::Error &e, const HttpTyp typ, const std::string &url, void (*func)());
    };
}