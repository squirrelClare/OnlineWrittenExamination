#include <iostream>
class A {
public:
    A(){}
    A(int,int){}
    int sum(int lhs,int rhs)
    {
        return lhs+rhs;
    }

};


using namespace std;

int main()
{
    A a;
    {
        int (A::*func)(int,int)=&A::sum;
        cout<<(a.*func)(12,3)<<endl;
    }
    {
        int (A::*func)(int,int)=&A::sum;
        cout<<(a.*func)(12,3)<<endl;
    }
    return 0;
}

