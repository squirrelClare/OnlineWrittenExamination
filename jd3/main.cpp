
#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int m=0,n=0;
    cin>>n>>m;
    vector<int> vec(2*m,0);
    for (int i = 0; i < 2*m; ++i) {
        cin>>vec[i];
    }

    for (int i = 0; i < vec.size(); ++i) {
        cout<<vec[i]<<endl;
    }
}

int main()
{
    solve();
    return 0;
}

