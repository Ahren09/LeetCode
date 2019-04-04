//Problem 3: Polymorphism and Inheritance

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Father
{
public:
    Father()
    {
        cout<<"This is father"<<endl;
    }
    
    virtual void func()
    {
        cout<<"Call father"<<endl;
    }
    
    //# Inheritance 1
    //Derived class should inherit destructor function of Base class
    //Otherwise when we destroy an object of derived class, only its "base part"
    //gets destructed
    //Thus destructor function should be "virtual"
    virtual ~Father()
    {
        cout<<"Bye father"<<endl;
    }
    
};

class Son: public Father
{
public:
    Son()
    {
        cout<<"This is son"<<endl;
    }
    
    //# Inheritance 2
    //This function inherits the virtual function "func()" in Father class
    virtual void func()
    {
        cout<<"Call son"<<endl;
    }
    
    //# Polymorphism
    //This func() passes in a parameter
    //When we call func() with one parameter, we call this version
    //Otherwise if no parameter is passed in, we call the one above
    void func(string name)
    {
        cout<<"Let's call "<<name<<endl;
    }
    
    ~Son()
    {
        cout<<"Bye son"<<endl;
    }
    
};

class Daughter: public Father
{
public:
    Daughter()
    {
        cout<<"This is daughter"<<endl;
    }
    
    //# Inheritance 2
    //This function inherits the virtual function "func()" in Father class
    virtual void func()
    {
        cout<<"Call daughter"<<endl;
    }
};

class Grandson: public Son, public Daughter
{
public:
    Grandson()
    {
        cout<<"This is grandson"<<endl;
    }
    
    //# Multiple inheritance
    //By calling foo(), both versions of foo() in Daughter and Son will be called
    virtual void foo()
    {
        Son::func();
        Daughter::func();
    }
    
};

int main()
{
    Father f;
    Son s;
    f.func();
    s.func();
    s.func("Alibaba!!");
    cout<<endl;
    
    //# Multiple inheritance
    //By calling foo(), both versions of func() in Daughter and Son will be called
    Grandson g;
    g.foo();
    cout<<endl;
    
    /*Result is:
     This is father
     This is father
     This is son
     Call father
     Call son
     Let's call Alibaba!!
     
     This is father
     This is son
     This is father
     This is daughter
     This is grandson
     Call son
     Call daughter
     
     Bye father
     Bye son
     Bye father
     Bye son
     Bye father
     Bye father
     */
    
}
