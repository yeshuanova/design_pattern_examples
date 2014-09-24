//
//  main.cpp
//  dp_composite
//
//  Created by Peter.Li on 2014/9/23.
//  Copyright (c) 2014年 Peter.Li. All rights reserved.
//

#include <iostream>
#include <memory>
#include <vector>

class BaseShape {
public:
    virtual void drawShape() {}
    virtual void add(std::shared_ptr<BaseShape>& shape) {}
    virtual void add(const std::shared_ptr<BaseShape>&& shape) {}
    virtual void removeLast() {}
    virtual int getArea() = 0;
};

class ShapeCollection : public BaseShape {
public:
    ShapeCollection() {
        _shape_collect.clear();
    }
    
    ShapeCollection(const std::string& collect_name) {
        _collect_name = collect_name;
    }
    
    virtual void drawShape() {
        std::cout << "Draw Collection: " << _collect_name << std::endl;
        for(auto& shape_ele : _shape_collect) {
            std::cout << "  ";
            shape_ele->drawShape();
        }
    }
    
    virtual void add(std::shared_ptr<BaseShape>& shape) {
        _shape_collect.push_back(shape);
    }
    
    virtual void add(const std::shared_ptr<BaseShape>&& shape) {
        _shape_collect.push_back(shape);
    }
    
    virtual void removeLast() {
        _shape_collect.pop_back();
    }
    
    virtual int getArea() {
        int sum_area = 0;
        for (const auto& shape : _shape_collect) {
            sum_area += shape->getArea();
        }
        return sum_area;
    }
    
private:
    std::vector<std::shared_ptr<BaseShape>> _shape_collect;
    std::string _collect_name = "No name";
};

class LineShape : public BaseShape {
public:
    virtual void drawShape(){
        std::cout << "Draw LineShape" << std::endl;
    }
    virtual int getArea() {
        return 2;
    }
};

class RectShape : public BaseShape {
    virtual void drawShape() {
        std::cout << "Draw RectShape" << std::endl;
    }
    virtual int getArea() {
        return 3;
    }
};

class CircleShape : public BaseShape {
    virtual void drawShape() {
        std::cout << "Draw CircleShape" << std::endl;
    }
    virtual int getArea() {
        return 4;
    }
};

class TextShape : public BaseShape {
    virtual void drawShape() {
        std::cout << "Draw TextShape" << std::endl;
    }
    virtual int getArea() {
        return 5;
    }
};


int main(int argc, const char * argv[]) {
    
    auto top_shape = std::shared_ptr<BaseShape>(new ShapeCollection("Top Collection"));
    top_shape->add(std::make_shared<LineShape>());
    top_shape->add(std::make_shared<RectShape>());
    
    auto down_shape = std::shared_ptr<BaseShape>(new ShapeCollection("Down Collection"));
    down_shape->add(std::make_shared<CircleShape>());
    down_shape->add(std::make_shared<TextShape>());
    top_shape->add(down_shape);
    top_shape->drawShape();
    std::cout << "shape area = " << top_shape->getArea() << std::endl;
    
    std::cout << std::endl << "Remove Last component" << std::endl;
    top_shape->removeLast();
    top_shape->drawShape();
    std::cout << "shape area = " << top_shape->getArea() << std::endl;
    
    return 0;
}
