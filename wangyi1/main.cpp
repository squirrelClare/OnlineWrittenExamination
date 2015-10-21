#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
    int t;
    if (a < b) {
        t = a;
        a = b;
        b = t;
    }
    while (t = a % b) {
        a = b;
        b = t;
    }
    return b;
}
int maxFightValue(int value,vector<int> vec){
    int tmpGcd=0;
    for (int i = 0; i < vec.size(); ++i) {
        tmpGcd=gcd(value,vec.at(i));
        value+=(value>vec[i])?vec[i]:tmpGcd;
    }
    return value;
}

void solve(){
    while (true) {
        int n=0;
        int value=0;
        cin>>n>>value;

        vector<int> vec(n,0);
        for (int i = 0; i < n; ++i) {
            cin>>vec[i];
        }
        cout<<maxFightValue(value,vec)<<endl;
    }
}

int main()
{
    solve();
    return 0;
}

