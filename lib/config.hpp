#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <chrono>
#include <map>
#include <memory>

#include "error.hpp"

namespace conf
{
    typedef std::chrono::system_clock::duration duration;

    // 配置类
    class Config
    {
    public:
        static std::unique_ptr<Config> Instance()
        {
            // if (instance == nullptr)
            //     instance = new Config();
            // return instance;
        };

    private:
        std::unique_ptr<Config> instance; // 单例
        bool bLoad = false;               // 是否加载过

    public:
        Config(){};

        ~Config(){};

        /*
         * 加载配置，只能调用一次
         */
        std::shared_ptr<err::Error> Load(const std::string &path);
        /**
         * 重新加载配置，可以调用多次
         */
        std::shared_ptr<err::Error> Reload(const std::string &path);
    };

} // namespace config

#endif