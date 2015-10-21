#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int sum(int lhs, int rhs)
{
    return lhs+rhs;
}

int main()
{
    //赋值和调用方法一
    {
        int (*p)(int,int) = sum;
        cout<<(*p)(1,2)<<endl;
    }

    //赋值和调用方法二
    {
        int (*p)(int,int) = &sum;
        cout<<p(1,2)<<endl;
    }

    return 0;
}

