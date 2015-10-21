#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
using namespace std;
void getlineTest();
void test2();
void test3();
void test4();
void test5();
std::vector<std::string> split(std::string str,std::string pattern);
int main()
{
//    stringstream ss;
//    string s;
//    getline(cin,s);
//    cout<<s<<endl;
//    ss<<s;
//    int a;
//    ss>>a;
//    cout<<a+34<<endl;
    test5();
    return 0;
}
void getlineTest() {
    char str[8];
    cin.getline(str, 5);
    cout<<str<<endl;
    cout<<"****************"<<endl;
    cin.getline(str, 5);
    cout<<str<<endl;
}
void test2() {
    char str1[10], str2[10];
    cin>>str1;
    cin>>str2;
    cout<<str1<<endl;
    cout<<str2<<endl;
}
void test3() {
    char* a;
    cin.getline(a,4);
    cout<<(int)a[0]<<endl;
}
void test4() {
    string s;
    getline(cin,s);
    cout<<s<<"**"<<endl;
    cout<<s.size()<<endl;

}

//字符串分割函数
std::vector<std::string> split(std::string str,std::string pattern)
{
    std::string::size_type pos;
    std::vector<std::string> result;
    str+=pattern;//扩展字符串以方便操作
    int size=str.size();

    for(int i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
            std::string s=str.substr(i,pos-i);
            result.push_back(s);
            i=pos+pattern.size()-1;
        }
    }
    return result;
}
void test5()
{
    int s=0,n;
    for(n=0;n<4;n++)
    {
        switch(n)
        {
            default:s+=4;
            case 1:s+=1;break;
            case 2:s+=2;break;
            case 3:s+=3;
//            cout<<n<<"    "<<s<<endl;
         }
        cout<<n<<"    "<<s<<endl;
    }
    cout<<"s=="<<s<<endl;
}
