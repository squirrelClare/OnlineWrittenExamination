#include <iostream>

using namespace std;
void f(int &a){
    if(a==0||a==1)
        return;
    cout<<a<<endl;
    a=a/2;
    f(a);
}

int main()
{
    int i=123;
    f(i);
//    cout<<i<<endl;
    return 0;
}

