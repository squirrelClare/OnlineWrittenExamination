#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stack>
using namespace std;

void solve(){
    deque<char> qu;
    int n=0;
    cin>>n;

    string str;
    for (int i = 0; i < n; ++i) {
        cin >> str;

        deque<char> qu;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i]=='@') {
                qu.clear();
                continue;
            }
            if (str[i]=='#') {
                qu.pop_back();
                continue;
            }
            qu.push_back(str[i]);
        }
        string tmp(qu.begin(),qu.end());    //重组字符串
        cout<<tmp<<endl;
    }
}

int main()
{
    solve();
    return 0;
}

