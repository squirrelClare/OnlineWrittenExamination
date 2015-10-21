#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool myequal(vector<int> x,vector<int> y){
    for (int i = 0; i < x.size(); ++i) {
        if (x[i]!=y[i]) {
            return false;
        }
    }
    return true;
}

void work(){
    int n=0;
    cin>>n;
    vector<int> myVec(n,0);
    for (int i = 0; i < n; ++i) {
        cin>>myVec[i];
    }

    vector<int> vec2(myVec);
    sort(vec2.begin(),vec2.end());

    vector<int> tags;
    for (int i = 0; i < vec2.size(); ++i) {
        if (myVec[i]!=vec2[i]) {
            tags.push_back(i);
        }
    }
    if (tags.size()==0) {
        cout<<"no"<<endl;
        return;
    }else{
        if ((*(tags.end()-1)-tags[0])!=(tags.size()-1)) {
            cout<<"no"<<endl;
        }
        return;
    }

    vector<int> x;
    vector<int> y;
    for (int i = 0; i < tags.size(); ++i) {
        x.push_back(myVec[tags[i]]);
    }
    for (int i = tags.size()-1; i >=0 ; --i) {
        y.push_back(vec2[tags[i]]);
    }
    if (myequal(x,y)) {
        cout<<"yes"<<endl;
        return;
    }
}

int main()
{
    work();
    return 0;
}

