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
        uint32_t Code = 0;
        // 错误信息
        const char *Desc = "未知错误";

        Error(uint32_t code, const char *desc)
        {
            Code = code;
            Desc = desc;
        }

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