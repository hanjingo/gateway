#include <gateway.hpp>
#include <iostream>
#include <memory>

int main() {
    std::cout << "gateway run" << std::endl;
    
    std::unique_ptr<gateway::Gateway> app;
    app->Init();
    app->Run();
}