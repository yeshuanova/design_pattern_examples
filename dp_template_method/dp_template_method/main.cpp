//
//  main.cpp
//  dp_template_method
//
//  Created by Peter.Li on 2014/9/23.
//  Copyright (c) 2014年 Peter.Li. All rights reserved.
//

#include <iostream>


class BaseTM {
public:
    void doTemplateMethod() {
        doPreProcess();
        doMainProcess();
        doPostProcess();
    };
    
protected:
    virtual void doPreProcess() {
        std::cout << "Do base pre-process" << std::endl;
    }
    
    virtual void doMainProcess() {
        std::cout << "Do base main-process" << std::endl;
    }
    
    virtual void doPostProcess(){
        std::cout << "Do base post-process" << std::endl;
    }
};

class CustomPreProcess : public BaseTM {
protected:
    virtual void doPreProcess() {
        std::cout << "Do custom pre-process" << std::endl;
    }
};

class CustomMainProcess : public BaseTM {
protected:
    virtual void doMainProcess() {
        std::cout << "Do custom main-process" << std::endl;
    }
};


int main(int argc, const char * argv[]) {

    BaseTM base_process;
    CustomPreProcess pre_process;
    CustomMainProcess main_process;
    
    std::cout << "Run base process: " << std::endl;
    base_process.doTemplateMethod();
    
    std::cout << std::endl << "Run custom pre-process:" << std::endl;
    pre_process.doTemplateMethod();
    
    std::cout << std::endl << "Run custom main-process:" << std::endl;
    main_process.doTemplateMethod();

    return 0;
}
