#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
//最大递增子序列
using namespace std;
bool isLess(pair<int,vector<int> > lhs,pair<int,vector<int> > rhs){
    return lhs.second.size()<rhs.second.size();
}

vector<int> getMaxSeq(vector<int> vec){
    map<int,vector<int> > tmpMap;
    for (int i = 0; i < vec.size(); ++i) {
        tmpMap[vec[i]]=vector<int>(0,0);
    }
    for (int i = 0; i < vec.size(); ++i) {
        vector<int> tmpVec;
        int tag=-10000;
        int max=0;
        for (int j = 0; j<i; ++j) {
            if (tmpMap[vec[j]].size()>max && *(tmpMap[vec[j]].end()-1)<vec[i]) {
                max=tmpMap[vec[j]].size();
                tag=j;
            }
        }
        if (tag!=-10000) {
            tmpVec=tmpMap[vec[tag]];
        }

        tmpVec.push_back(vec[i]);
        tmpMap[vec[i]]=tmpVec;
    }

    return max_element(tmpMap.begin(),tmpMap.end(),isLess)->second;
}

int main()
{
    int a[10]={35, 36, 39, 3, 15, 27, 6, 42};
    vector<int> vec(a,a+10);
    vec=getMaxSeq(vec);
    for (int i = 0; i < vec.size(); ++i) {
        cout<<vec[i]<<endl;
    }
    return 0;
}

