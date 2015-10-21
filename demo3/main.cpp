#include <iostream>
#include <string>
using namespace std;

bool isHuiWen(string str)
{
    int n=str.size();
    int tag=n/2;
    for(size_t i=0;i<tag;++i){
        if(str[i]!=str[n-1-i])
            return false;
    }
    return(true);
}

int maxSizeHuiWen(string str)
{
    int n=str.size();

    for(size_t i=n;i>0;--i)
    {
        for(size_t j=0;j<=n-i;++j)
        {
            if(isHuiWen(str.substr(j,i)))
                return i;
        }
    }
}
int main()
{
    int n=0;
    cin>>n;
    int i=0;
    string tmpStr;
    while(i<n)
    {
        ++i;
        cin>>tmpStr;
        cout<<maxSizeHuiWen(tmpStr)<<endl;
    }
    return 0;
}
