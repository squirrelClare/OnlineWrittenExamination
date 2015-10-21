#include<iostream>
#include<string>
using namespace std;
int main() {
        // write code here

    string str="afdafdasaaabbbbrrr";
    int n=str.length();
    for(int k=0;k<str.length();k++){
        char tmp;
        tmp=str[k];
        cout<<tmp;
        if((tmp<'A')|| (tmp>'z')){
            cout<<str[k]<<'\n'<<"bu符合要求aZ"<<'\n';
        }
    }

    int i=0;
    int j;
    int count=0;
    string ch;

    string s(str);
    //判断字符串是否都是字母

    if(n<=0)
        cout<<"不符合要求";
    else
    {
        while(i<n)

        {
                j=i;
                while(str.at(j)==str.at(i)){
                    count++;
                    j++;
                    if(j>=n)
                        break;
                }

                    if(count==1){
                        str.insert(i+1,1,'1');
                        i=i+2;
                        n=n+1;
                    }
                    else
                    {
                        ch=count+'0';
                        str.replace(i+1,count-1,ch);
                        i=i+2;
                        n=n+2-count;
                    }
            count=0;
        }
    }
        int m=str.length();
        if(m<n)
        {
        for(int k=0;k<m;k++)
            cout<<s.at(k);
        cout<<endl;
        }
        else
            {
        for(int k=0;k<m;k++)
            cout<<str.at(k);
            cout<<endl;
        }
        return 0;
}
