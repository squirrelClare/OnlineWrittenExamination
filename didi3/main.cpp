#include <iostream>
#include <algorithm>
using namespace std;
char* fast_strnstr(const char* str1,const char* str2,size_t n){
    string s1(str1);
    string s2(str2);
    s1=s1.substr(0,n);

    if (s1.find_first_of(s2,0)!=string::npos) {
        const char* tmp;
        tmp=s1.c_str();
        return &s1[s1.find_first_of(s2,0)];
    }else{
        return NULL;
    }
}

int main()
{
    cout << fast_strnstr("sdadasda","da",5) << endl;
    return 0;
}

