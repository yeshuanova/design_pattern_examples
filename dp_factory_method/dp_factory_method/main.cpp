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
    virtual std::shared_ptr<BaseProduct> getProduct() = 0;
};

class CreatorApple : public AbstractCreator {
protected:
    virtual std::shared_ptr<BaseProduct> getProduct() {
        return std::make_shared<ProductApple>();
    }
};

class CreatorOrange : public AbstractCreator {
protected:
    virtual std::shared_ptr<BaseProduct> getProduct() {
        return std::make_shared<ProductOrange>();
    }
};

template <class CreateType>
class CreatorTMP {
public:
    void doOperation() {
        getProdoct()->runAction();
    }
    
protected:
    std::shared_ptr<BaseProduct> getProdoct() {
        return std::make_shared<CreateType>();
    }
    
};

int main(int argc, const char * argv[])
{
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

