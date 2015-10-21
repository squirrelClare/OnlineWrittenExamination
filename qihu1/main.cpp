#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>
using namespace std;

bool isIn(vector<int> vec ,int x){
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i]==x) {
            return true;
        }
    }
    return false;
}

int computer(vector<pair<int,int> > vec){
    deque<int> tags;

    set<int> tmpSet;
    vector<int> old;

    tags.push_back(1);
    while (tags.size()!=0) {
        int tmp=tags[0];
        old.push_back(tmp);
        for (int i = 0; i < vec.size(); ++i) {
            if (vec.at(i).first==tmp) {
                tmpSet.insert(vec.at(i).second);
                if (!isIn(old,vec.at(i).second)) {
                    tags.push_back(vec.at(i).second);
                }

            }
            if (vec.at(i).second==tmp) {
                tmpSet.insert(vec.at(i).first);
                if (!isIn(old,vec.at(i).first)) {
                    tags.push_back(vec.at(i).first);
                }
            }
        }
        tags.pop_front();
    }
    for (set<int>::iterator it = tmpSet.begin(); it!=tmpSet.end(); ++it) {
        if (*it==1) {
            return tmpSet.size()-1;
        }
    }
   return tmpSet.size();
}

void solve(){

    vector<int> nVec;
    while (true) {
        int N=0,M=0;
        cin>>N>>M;
        if (N==0&&M==0) {
            break;
        }

        vector<pair<int,int> > vec;
        for (int i = 0; i < M; ++i) {
            int x=0;
            int y=0;
            cin>>x>>y;
            vec.push_back(make_pair<int,int>(x,y));
        }
        nVec.push_back(computer(vec));
    }

    for (int i = 0; i < nVec.size(); ++i) {
        cout<<nVec[i]<<endl;
    }
}


int main()
{
    solve();
    return 0;
}

