#include <gateway.hpp>
#include <iostream>
#include <memory>
#include <logger.hpp>
#include <config.hpp>
#include <error.hpp>

int main() {
    err::Error e{};
    std::string path = "";

    gateway::Config::Instance()->Load(e, path);
    //if(e != Ok)
    log::Logger::Instance()->Info();
    
    std::unique_ptr<gateway::Gateway> app(new gateway::Gateway());
    app->Init();
    app->Run();

    return 0;
}