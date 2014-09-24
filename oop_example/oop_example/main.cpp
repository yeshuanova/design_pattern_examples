//
//  main.cpp
//  design_pattern_examples
//
//  Created by Peter.Li on 2014/9/22.
//  Copyright (c) 2014年 Peter.Li. All rights reserved.
//

#include <iostream>
#include <memory>

class Shape {
public:
    void drawShape() {
        onDraw();
    }
protected:
    virtual void onDraw() = 0;
    
private:
    
};


class Circle : public Shape {
public:
    Circle(int radius) : _radius(radius) {}
    
protected:
    void onDraw() {
        std::cout << "Draw Circle, Area is " << _radius * _radius << std::endl;
    }
    
private:
    int _radius;
};

class Rect : public Shape {
public:
    Rect(int width, int height) : _width(width), _height(height){}
    
protected:
    void onDraw() {
        std::cout << "Draw Rect, Area is " << _width * _height << std::endl;
    }
    
private:
    int _width;
    int _height;
};

class Triangle : public Shape {
public:
    Triangle(int width, int height): _width(width), _height(height){}
protected:
    void onDraw() {
        std::cout << "Draw Triangle, Area is " << _width * _height / 2 << std::endl;
    }
private:
    int _width;
    int _height;
};

int main(int argc, const char * argv[])
{
    std::cout << "Polymorphism example\n";
    
    std::shared_ptr<Shape> circle = std::make_shared<Circle>(5);
    std::shared_ptr<Shape> rect = std::make_shared<Rect>(2, 3);
    std::shared_ptr<Shape> triangle = std::make_shared<Triangle>(2, 3);
    
    circle->drawShape();
    rect->drawShape();
    triangle->drawShape();
    
    return 0;
}

