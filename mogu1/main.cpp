#include <iostream>
#include <vector>
using namespace std;

int maxValue(vector<int> vec,int index){
    vector<int> tmp;
    for (int i = 0; i < vec.size(); ++i) {
        if(i!=index){
            tmp.push_back(vec[i]);
        }
    }

    int value=-10000;
    for (int i = 1; i < tmp.size(); ++i) {
        if (tmp[i]-tmp[i-1]>value) {
            value=tmp[i]-tmp[i-1];
        }
    }
    return value;
}

void solve(){
    int n;
    cin>>n;
    vector<int> vec(n,0);
    for (int i = 0; i < n; ++i) {
        cin>>vec[i];
    }
    int value=10000000000;
    int tmp=-10;
    for (int i = 1; i < n-1; ++i) {
        tmp=maxValue(vec,i);
        if (tmp<value) {
            value=tmp;
        }
    }
    cout<<value<<endl;
}

int main()
{
    solve();
    return 0;

}

