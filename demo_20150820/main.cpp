#include <iostream>
#include <string>
using namespace std;

struct s {

    double value6;
    int value1;
    bool value2;
    char value3;
} myStruct;


void test1();
int test2(int,int);
int test3(int,int);
int main()
{
    cout<<sizeof(s)<<endl;
    cout<<0x17<<endl;
    cout<<test2(15,5)<<endl;
    cout<<"*******************"<<endl;
    cout<<test3(121,3)<<endl;
    return 0;
}

void test1(){
    cout<<sizeof(double)<<endl;
    cout<<sizeof(float)<<endl;
    cout<<sizeof(long)<<endl;
    cout<<sizeof(short)<<endl;
    cout<<sizeof(int)<<endl;
    cout<<sizeof(char)<<endl;
    cout<<sizeof(unsigned)<<endl;
    cout<<sizeof(bool)<<endl;
}
int test2(int lhs, int rhs){
    cout<<(lhs&rhs)<<endl;
    cout<<(lhs|rhs)<<endl;
    return ((lhs&rhs)+(lhs|rhs))>>1;
}
int test3(int lhs, int rhs){
    cout<<(lhs&rhs)<<endl;
    cout<<(lhs^rhs)<<endl;
    return (lhs&rhs)+((lhs^rhs)>>1);
}
