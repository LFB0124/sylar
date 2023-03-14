#ifndef _SYLAR_LOG_H_
#define _SYLAR_LOG_H_

#include <memory>
#include <string>

namespace sylar{

    //日志事件
    class LogEvent{
    public: 

        typedef std::shared_ptr<LogEvent> ptr;

        LogEvent();

    private:

        const char* m_file = nullptr;   //日志文件名
        int32_t m_line = 0;             //行号
        uint32_t m_elapse = 0;          //程序启动开始到现在的毫秒数
        uint32_t m_threadId = 0;        //线程号
        uint32_t m_fiberId = 0;         //协程号
        uint64_t m_time = 0;            //时间戳
        std::string m_content;          //内容
    };



    //日志级别
    class logLevel{
    public:

        enum Level{

            UNKNOW = 0,

            DEBUG = 1,

            INFO = 2,

            WARN = 3,

            ERROR = 4,

            FATAL = 5

        };
    };



    //日志格式器
    class LogFormatter{
    public:

        typedef std::shared_ptr<LogFormatter> ptr;

        explicit LogFormatter(const std::string& opattern);

        std::string format(LogEvent::ptr event);

    private:
        std::string m_pattern;



    };

}


#endif // !_SYLAR_LOG_H_