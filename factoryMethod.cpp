#pragma once
#include <iostream>
#include <string>

using namespace std;

enum class LogLevel {
    Debug,
    INFO,
    ERROR
};

class ILogger {
public:
    virtual void log(const string& msg) = 0;
    virtual ~ILogger() {}
};


class ILoggerFactory {
public:
    virtual ILogger* createLogger() = 0;
};

// DebugLogger class
class DebugLogger : public ILogger {
public:
    void log(const string& msg) override {
        cout << "DEBUG : " << msg << endl;
    }
};

// DebugLoggerFactory class
class DebugLoggerFactory : public ILoggerFactory {
public:
    ILogger* createLogger() override {
        return new DebugLogger();
    }
};

// ErrorLogger class
class ErrorLogger : public ILogger {
public:
    void log(const string& msg) override {
        cout << "ERROR : " << msg << endl;
    }
};

// ErrorLoggerFactory class
class ErrorLoggerFactory : public ILoggerFactory {
public:
    ILogger* createLogger() override {
        return new ErrorLogger();
    }
};

// InfoLogger class
class InfoLogger : public ILogger {
public:
    void log(const string& msg) override {
        cout << "INFO : " << msg << endl;
    }
};

// InfoLoggerFactory class
class InfoLoggerFactory : public ILoggerFactory {
public:
    ILogger* createLogger() override {
        return new InfoLogger();
    }
};



int main() {
    ILoggerFactory* loggerFactory1 = new InfoLoggerFactory;
    ILogger* infoLogger = loggerFactory1->createLogger();

    ILoggerFactory* loggerFactory2 = new ErrorLoggerFactory;
    ILogger* errorLogger = loggerFactory2->createLogger();

    ILoggerFactory* loggerFactory3 = new DebugLoggerFactory;
    ILogger* debugLogger = loggerFactory3->createLogger();

    debugLogger->log("This is a debug log msg");
    infoLogger->log("This is an info log msg");
    errorLogger->log("This is an error log msg");

    delete debugLogger;
    delete infoLogger;
    delete errorLogger;

    return 0;
}

