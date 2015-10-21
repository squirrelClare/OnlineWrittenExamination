#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass
{
public:
    MyClass();
   // int a;
    ~MyClass();
    int show(){
        return 13;
    }

private:
    virtual int get(){
    return 2;
}

};

#endif // MYCLASS_H
