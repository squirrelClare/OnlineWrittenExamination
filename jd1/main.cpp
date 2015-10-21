#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(){
    int n=0;
    cin>>n;
    vector<double> vec(n,0);
    for (int i = 0; i < n; ++i) {
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());

    int tag=0;
    double w=2,l=20;
    for (int i = n-1; i > 0; --i) {
        if (l<=0) {
            break;
        }

        if (l>w) {
            double tmp=l;
            w=l;
            l=tmp;
        }
        tag++;
        l-=2*vec[i];

    }
    cout<<tag<<endl;
}

int main()
{
    solve();
    return 0;
}

