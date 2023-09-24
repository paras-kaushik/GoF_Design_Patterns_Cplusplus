#include <iostream>
#include <string>

enum class LogLevel {
    Debug,
    INFO,
    ERROR
};

class ILogger {
public:
    virtual void log(const std::string& msg) = 0;
    virtual ~ILogger() {} // Add a virtual destructor
};

class DebugLogger : public ILogger {
public:
    void log(const std::string& msg) override {
        std::cout << "DEBUG : " << msg << std::endl;
    }
};

class InfoLogger : public ILogger {
public:
    void log(const std::string& msg) override {
        std::cout << "INFO : " << msg << std::endl;
    }
};

class ErrorLogger : public ILogger {
public:
    void log(const std::string& msg) override {
        std::cout << "ERROR : " << msg << std::endl;
    }
};

class LoggerFactory {
public:
    static ILogger* createLogger(LogLevel pLogLevel) {
        if (pLogLevel == LogLevel::Debug)
            return new DebugLogger();
        if (pLogLevel == LogLevel::INFO)
            return new InfoLogger();
        if (pLogLevel == LogLevel::ERROR)
            return new ErrorLogger();
        return nullptr;
    }
};

int main() {
    ILogger* debugLogger = LoggerFactory::createLogger(LogLevel::Debug);
    ILogger* infoLogger = LoggerFactory::createLogger(LogLevel::INFO);
    ILogger* errorLogger = LoggerFactory::createLogger(LogLevel::ERROR);

    debugLogger->log("This is a debug log msg");
    infoLogger->log("This is an info log msg");
    errorLogger->log("This is an error log msg");

    delete debugLogger;
    delete infoLogger;
    delete errorLogger;

    return 0;
}

