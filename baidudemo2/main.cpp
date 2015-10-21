#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
bool isTrue(int n){
    vector<int> rec;
    int tmp=n;

    while (n>=10) {
        rec.push_back(n%10);
        n/=10;
    }
    rec.push_back(n);

    int m=rec.size();
    for (int i = 0; i < rec.size(); ++i) {
        tmp-=pow(rec.at(i),m);
    }
    return tmp==0;
}

void solve(int m,int n){
    vector<int> rec;
    for (int i = m; i <= n; ++i) {
        if (isTrue(i)) {
            rec.push_back(i);
        }
    }
    if (rec.size()==0) {
        cout<<"no"<<endl;
    }else{
        for (int i = 0; i < rec.size(); ++i) {
            cout<<rec[i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int m=0,n=0;
    while (cin>>m>>n) {
        solve(m,n);
    }
    return 0;
}

