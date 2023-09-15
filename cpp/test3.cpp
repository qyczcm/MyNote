#include <iostream>
#include <vector>
#include <string>

using namespace std;

class A
{
    virtual void foo();
    virtual void goo();
};
class B : public A
{
    virtual void foo() override; //True
    // virtual void fo0() override; //false

    virtual void goo() final;//被override并且是最后一个override，在其子类中不可以重写

};
class C : public B
{
    // virtual void goo() override;//false
};

int main()
{
    
    return 0;
}
