/*
    Hitender Prakash
    simple example of how to implement singleton design pattern in c++
    contains minimal and simple code
*/

#include <iostream>
#include <string>
#include <thread>
#include <mutex>

//singleton class
class single{
private:
    //make constructor private so that class objects can not be instantiated from outside the class directly
    single(){};

    //declare static variable of class
    //
    //mutex to protect the genSingle method in case of parallel scenarios
    static std::mutex mu;

    //handle of single object
    static single *handle;
public:
    //public method to enable the instantiation of class
    static single *genSingle();
};

//define static variable of class
std::mutex single::mu;
single *single::handle = 0;
single* single::genSingle(){
    std::lock_guard<std::mutex> lock(mu);
    if(!handle){
        //introduce delay
        //puting cout statement so compiler does not remove it in optimization
        for(int i=0;i<20;i++){std::cout<<" "<<"\b";}
        //create new only if handle is null, otherwise return the same old handle
        handle=new single();
    }
    return handle;
}

//function to call in a separate thread, try to make multiple objects of singleton class simultaneously
void threaded_gen(single **p){
    *p = single::genSingle();
}

//driver code
int main()
{
    std::cout<<"\nDriver code for testing singleton";
    std::cout<<"\n========================================";
    single *s1;
    single *s2;

    std::thread t1(threaded_gen,&s1);
    std::thread t2(threaded_gen,&s2);
    t1.join();
    t2.join();

    std::cout<<"\nFirst Object instantiated: "<<(void*)s1;
    std::cout<<"\nSecond Object instantiated: "<<(void*)s2;
    if(s1==s2){
        //emplies that only single object was created
        std::cout<<"\nSingleton property preserved";
    }
    else{
        std::cout<<"\nOops singleton property violated";
    }
    std::cout<<"\n========================================\n";
    return 0;
}
