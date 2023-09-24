#include <iostream>
#include <string>

using namespace std;

class ILogger {
public:
    virtual void log(const string& msg) = 0;
    virtual ~ILogger() {}
};

class WindowsDebugLogger : public ILogger {
public:
    void log(const string& msg) {
        cout << "Windows Debug Logger: " << msg << endl;
    }
};
class WindowsInfoLogger : public ILogger {
public:
    void log(const string& msg) {
        cout << "Windows Info Logger: " << msg << endl;
    }
};
class WindowsErrorLogger : public ILogger {
public:
    void log(const string& msg) {
        cout << "Windows Error Logger: " << msg << endl;
    }
};
class MacDebugLogger : public ILogger {
public:
    void log(const string& msg) {
        cout << "Mac Debug Logger: " << msg << endl;
    }
};
class MacInfoLogger : public ILogger {
public:
    void log(const string& msg) {
        cout << "Mac Info Logger: " << msg << endl;
    }
};
class MacErrorLogger : public ILogger {
public:
    void log(const string& msg) {
        cout << "Mac Error Logger: " << msg << endl;
    }
};

class ILogFactory {
public:
    virtual ILogger* createDebugLogger() = 0;
    virtual ILogger* createInfoLogger() = 0;
    virtual ILogger* createErrorLogger() = 0;
    virtual ~ILogFactory() {}
};

// Concrete Factory 1: WindowsLogFactory
class WindowsLogFactory : public ILogFactory {
public:
    ILogger* createDebugLogger() {
        return new WindowsDebugLogger();
    }

    ILogger* createInfoLogger() {
        return new WindowsInfoLogger();
    }

    ILogger* createErrorLogger() {
        return new WindowsErrorLogger();
    }
};

class MacLogFactory : public ILogFactory {
public:
    ILogger* createDebugLogger() {
        return new MacDebugLogger();
    }

    ILogger* createInfoLogger() {
        return new MacInfoLogger();
    }

    ILogger* createErrorLogger() {
        return new MacErrorLogger();
    }
};

class AbstractLoggerFactory {
public:
    static ILogFactory* createFactory(string ostype) {
        if (ostype == "windows")
            return new WindowsLogFactory();
        else if (ostype == "mac")
            return new MacLogFactory();
        return nullptr;
    }
};

int main() {
    cout << "Enter machine OS (windows or mac): ";string ostype;
    cin >> ostype;

    ILogFactory* factory = AbstractLoggerFactory::createFactory(ostype);
    if (!factory) {cout << "Unsupported platform." << endl;return 1;}

    ILogger* debugLogger = factory->createDebugLogger();
    ILogger* infoLogger = factory->createInfoLogger();
    ILogger* errorLogger = factory->createErrorLogger();

    debugLogger->log("Debug message");
    infoLogger->log("Info message");
    errorLogger->log("Error message");
    return 0;
}

