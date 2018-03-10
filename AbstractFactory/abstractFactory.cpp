/*
    Hitender Prakash
    Example to demonstrate the implementation of Abstract Factory design Pattern
*/

#include <iostream>
#include <string>
#include <vector>

class shape{
 public:
     virtual void introduceSelf()=0;
     virtual ~shape(){}
};

class circle: public shape{
public:
    virtual void introduceSelf() override {
        std::cout<<"\nI am a circle";
    }
    virtual ~circle(){}
};

class ellipse: public shape{
public:
    virtual void introduceSelf() override {
        std::cout<<"\nI am a ellipse";
    }
    virtual ~ellipse(){}
};

class square: public shape{
public:
    virtual void introduceSelf() override {
        std::cout<<"\nI am a square";
    }
    virtual ~square(){}
};

class rectangle: public shape{
public:
    virtual void introduceSelf() override {
        std::cout<<"\nI am a rectangle";
    }
    virtual ~rectangle(){}
};

class shapeFactory{
public:
    virtual shape* createRoundedShape()=0;
    virtual shape* createAngledShape()=0;
};

class specialShapeFactory:public shapeFactory{
 public:
    shape* createRoundedShape(){
        return new circle();
    }
    shape* createAngledShape(){
        return new square();
    }
};

class generalShapeFactory:public shapeFactory{
public:
    shape* createRoundedShape(){
        return new ellipse();
    }
    shape* createAngledShape(){
        return new rectangle();
    }
};

int main()
{
    std::cout<<"\nDriver code for testing abstract factory";
    std::cout<<"\n========================================";
    std::vector<shape*> vec;
    shapeFactory *factory = new generalShapeFactory();
    vec.push_back(factory->createRoundedShape());
    vec.push_back(factory->createAngledShape());
    delete factory;
    factory = new specialShapeFactory();
    vec.push_back(factory->createRoundedShape());
    vec.push_back(factory->createAngledShape());
    for(auto i:vec){
        i->introduceSelf();
    }

    std::cout<<"\n========================================\n";
    return 0;
}
