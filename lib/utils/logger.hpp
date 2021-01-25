#pragma once

#include <string>
#include <iostream>
#include <memory>

namespace log
{
    class LoggerCfg 
    {

    };

    class Logger 
    {
    private:
        static std::shared_ptr<Logger> _instance; // 单例

    public:
        static std::shared_ptr<Logger> Instance()
        {
            if (_instance == nullptr) { 
                _instance = std::make_shared<Logger>(); 
            }
            return _instance;
        };

        Logger() {};
        ~Logger() {};

        void Debug();
        void Info();
        void Warn();
        void Error();
        void Fatal();
    };
}
