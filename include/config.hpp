#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <chrono>
#include <map>
#include "error.hpp"

namespace config
{
    using namespace err;

    typedef std::chrono::system_clock::duration duration;

    // 定义错误类型
    static const Error &ConfigAlreadyLoad{100U, "配置已经被加载过一次了"};
    static const Error &ConfigFileNotExist{101U, "配置文件不存在"};

    // 配置类
    class Config
    {
    public:
        static Config *Instance()
        {
            if (instance == nullptr)
                instance = new Config();
            return instance;
        };

    private:
        static Config *instance; //单例
        bool bLoad = false;      //是否加载过

    public:
        Config(){};

        ~Config(){};

        /*
         * 加载配置，只能调用一次
         */
        const err::Error &Load(const std::string &path);
        /**
         * 重新加载配置，可以调用多次
         */
        const err::Error &Reload(const std::string &path);
    };

} // namespace config

#endif