//
//  Logger.h
//  LLD_PARKING_LOT
//
//  Created by Paras Kaushik on 05/07/23.
//

#ifndef Logger_h
#define Logger_h
#include<iostream>
#include<string>
#include<mutex>

class Logger {
    static Logger* loggerInstace;
    static mutex mtx;
    Logger(){
        std::cout<<"new instance created"<<endl;
        // singleton constructors are used for initialation stuff , like
        // for DB example , this would initialise the databse
    }
public:
   
    void log(std::string msg){
        std::cout<<msg<<endl;
    }
    static Logger* getLoggerInstance(){
        // DOUBLE CHECK LOCKING as locks are really expesnive
        // so that we put the lock only once each thread
        // Check if an instance already exists (avoid locking overhead if already initialized)
        if(loggerInstace==nullptr) {
            mtx.lock();
            if(loggerInstace==nullptr)
                loggerInstace=new Logger();
            mtx.unlock();
        }
        
        
        return loggerInstace;
    }
    
    //deleting the copy constrctor
    Logger(Logger const &)=delete;
    // deleting the copy assignment operator
    void operator=(Logger const &)=delete;
};

Logger* Logger::loggerInstace=nullptr;
mutex Logger::mtx;// in c++ static variables must be define outside mandatorily

#endif /* Logger_h */
