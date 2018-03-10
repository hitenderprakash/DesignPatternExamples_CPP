/*
    Hitender Prakash
    Example to demonstrate the implementation of Factory design Pattern
*/
#include <iostream>
#include <string>
#include <vector>

//define super class
class superClass{
    public:
    //method needs to be virtual for dynamic polymorphism
    virtual void introduceSelf(){
        std::cout<<"\nI am a superClass object";
    }
    //factory method, return pointer of super class object
    static superClass* objectCreateFactoryMethod(int type);
};

//subclass one
class subClass_one: public superClass{
    public:
    virtual void introduceSelf() override {
        std::cout<<"\nI am a subClassOne object";
    }
};

//subclass two
class subClass_two: public superClass{
    public:
    virtual void introduceSelf() override {
        std::cout<<"\nI am a subClassTwo object";
    }
};

//define the factory method
superClass* superClass::objectCreateFactoryMethod(int type){
    if(type==0){
        //create super class object
        return new superClass();
    }
    else if(type==1){
        //create sub class 1 object
        return new subClass_one();
    }
    else{
        //create sub class 2 object
        return new subClass_two();
    }
}

int main()
{
    std::cout<<"\nDriver code for testing abstract factory";
    std::cout<<"\n========================================";

    //stores pointer to super class object
    //which can also point to derived class objects
    std::vector<superClass *> vec;

    //create object by using factory
    vec.push_back(superClass::objectCreateFactoryMethod(0));
    vec.push_back(superClass::objectCreateFactoryMethod(1));
    vec.push_back(superClass::objectCreateFactoryMethod(2));

    for(auto i:vec){
        i->introduceSelf();
    }
    std::cout<<"\n========================================\n";
    return 0;
}
