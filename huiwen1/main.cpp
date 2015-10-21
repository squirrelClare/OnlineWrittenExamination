#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
using namespace std;

int main()
{
//    char str1[1000];
//    char* str2=new char[1000];
//    cin.getline(str1,100);
//    cin.getline(str2,100);
//    cout<<"size="<<sizeof(str1)<<endl;
//    cout<<"size="<<strlen(str1)<<endl;
//    cout<<"str1="<<str1<<endl;
//    cout<<"str2="<<str2<<endl;
//    cout << "Hello World!" << endl;

//    char* p="dsada";
//    string s(p);
//    cout<<p<<endl;
//    cout<<s.size()<<endl;

//    stringstream ss;
//    int a=123;
//    string str="NULL";
//    ss<<a;
//    ss>>str;
//    cout<<str;


    char str[]="dsadad dsdas dsada";
    char* p;
    const char* d=" ";
    p=strtok(str,d);
    cout<<p<<endl;
    cout<<atof("321.312312")<<endl;
    return 0;
}

