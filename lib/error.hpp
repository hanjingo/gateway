#ifndef ERROR_HPP
#define ERROR_HPP

#include <string>
#include <map>

namespace err
{
    /**
     * Error 错误类
     */
    class Error
    {
    public:
        // 错误码
        uint32_t Code;
        // 错误信息
        std::string Desc;

        Error(uint32_t code = 0, const std::string &desc = "未知错误"):Code{code}, Desc{desc} {}

        inline bool operator==(const Error &e) const
        {
            return Code == e.Code;
        }

        inline bool operator!=(const Error &e) const
        {
            return Code != e.Code;
        }

        inline Error &operator=(const Error &e)
        {
            Code = e.Code;
            Desc = e.Desc;

            return *this;
        }
    };

} // namespace err

#endif