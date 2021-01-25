#include <gateway.hpp>
#include <iostream>
#include <memory>
#include <lib/utils/logger.hpp>
#include <config.hpp>
#include <lib/utils/error.hpp>

using namespace gateway;
using namespace log;

int main() {
    err::Error e{};
    std::string path = "";

    // Config::Instance()->Load(e, path);
    // if(e != Ok)
    Logger::Instance();
    
    std::unique_ptr<Gateway> app(new Gateway());
    app->Init();
    app->Run();

    return 0;
}