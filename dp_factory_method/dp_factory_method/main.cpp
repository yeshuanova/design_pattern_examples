//
//  main.cpp
//  dp_factory_method
//
//  Created by Peter.Li on 2014/9/22.
//  Copyright (c) 2014年 Peter.Li. All rights reserved.
//

#include <iostream>

class BaseProduct {
public:
    virtual void runAction() = 0;
};

class ProductApple : public BaseProduct {
public:
    void runAction() {
        std::cout << "ProductApple" << std::endl;
    }
};

class ProductOrange : public BaseProduct {
public:
    void runAction() {
        std::cout << "ProductOrange" << std::endl;
    }
};

class AbstractCreator {
    
public:
    void doOperation() {
        getProduct()->runAction();
    }
    
protected:
    virtual BaseProduct* getProduct() = 0;
};

class CreatorApple : public AbstractCreator {
protected:
    virtual BaseProduct* getProduct() {
        return new ProductApple();
    }
};

class CreatorOrange : public AbstractCreator {
protected:
    virtual BaseProduct* getProduct() {
        return new ProductOrange();
    }
};

template <typename create_type>
class CreatorTMP {
public:
    void doOperation() {
        getProdoct()->runAction();
    }
    
protected:
    BaseProduct* getProdoct() {
        return new create_type;
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << std::endl << "Run Point Creator:" << std::endl;
    CreatorApple apple;
    apple.doOperation();
    CreatorOrange orange;
    orange.doOperation();
    
    std::cout << std::endl << "Run Template Creator:" << std::endl;
    CreatorTMP<ProductApple> tmp_apple;
    tmp_apple.doOperation();
    CreatorTMP<ProductOrange> tmp_orange;
    tmp_orange.doOperation();
    
    return 0;
}

