#pragma once

#include <string>

namespace log
{
    class LoggerCfg 
    {

    };

    class Logger 
    {
    private:
        static Logger *instance; // 单例

    public:
        static Logger *Instance()
        {
            if (instance == nullptr)
                instance = new Logger();
            return instance;
        };

        Logger(){};
        ~Logger(){};

        void Debug()
        {

        };

        void Info()
        {

        };

        void Warn()
        {

        };

        void Error()
        {

        };

        void Fatal()
        {

        };
    };
}
