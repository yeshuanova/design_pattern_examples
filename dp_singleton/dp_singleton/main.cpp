//
//  main.cpp
//  dp_singleton
//
//  Created by Peter.Li on 2014/9/22.
//  Copyright (c) 2014年 Peter.Li. All rights reserved.
//

#include <iostream>
#include <memory>

class Singleton {

public:

    static Singleton& getInstance() {
        static Singleton instanceObj;
        return instanceObj;
    }
    
    std::string getMsg() {
        return "Call Singleton with static local object method";
    }

private:
    Singleton(){};
    
};

class SingletonPoint {
public:
    static SingletonPoint* getInstance() {
        if (_instance_ptr == nullptr) {
            std::cout << "Create point instance" << std::endl;
            _instance_ptr = new SingletonPoint;
        }
        return _instance_ptr;
    }
    
    std::string getMsg() {
        return "Call Singleton with point method";
    }
    
    static std::string getMsgTest() {
        return "Test Msg";
    }
    
private:
    
    SingletonPoint() {};
    
    static SingletonPoint* _instance_ptr;
};

SingletonPoint* SingletonPoint::_instance_ptr = nullptr;

class SingletonSharedPoint {
public:
    static std::shared_ptr<SingletonSharedPoint> getInstance() {
        if (_instance_ptr == nullptr) {
            std::cout << "Create shared point instance" << std::endl;
            _instance_ptr = std::shared_ptr<SingletonSharedPoint>(new SingletonSharedPoint());
        }
        return _instance_ptr;
    }
    
    std::string getMsg() {
        return "Call Singleton with shared_ptr method";
    }

private:
    SingletonSharedPoint() {};
    static std::shared_ptr<SingletonSharedPoint> _instance_ptr;
};

std::shared_ptr<SingletonSharedPoint> SingletonSharedPoint::_instance_ptr = std::shared_ptr<SingletonSharedPoint>();

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Singleton examples" << std::endl;
    
    std::cout << Singleton::getInstance().getMsg() << std::endl;
    std::cout << SingletonPoint::getInstance()->getMsg() << std::endl;
    std::cout << SingletonSharedPoint::getInstance()->getMsg() << std::endl;

    return 0;
}

