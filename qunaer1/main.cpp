#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
void solve(){
    map<int,int> m;
    int n=0,tmp=0;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>tmp;
        m[tmp]+=1;
    }
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>tmp;
        m[tmp]+=1;
    }
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>tmp;
        m[tmp]+=1;
    }

    vector<int> vec;
    for(map<int,int>::iterator it=m.begin();it!=m.end();++it){
        if ((*it).second==3) {
            vec.push_back((*it).first);
        }
    }

    sort(vec.begin(),vec.end());
    for (int i = 0; i < vec.size(); ++i) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    solve();
    return 0;
}

