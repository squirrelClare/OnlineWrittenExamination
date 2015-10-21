#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMaxValue(vector<int> src){
    int tmp=0;
    size_t n=src.size();
    for (size_t i = 0; i < n; ++i) {
        if (src[i]>tmp) {
            tmp=src[i];
        }
    }
    return tmp;
}

int getMinValue(vector<int> src){
    int tmp=10000;
    size_t n=src.size();
    for (size_t i = 0; i < n; ++i) {
        if (src[i]<tmp) {
            tmp=src[i];
        }
    }
    return tmp;
}

void sortValue(vector<int> &src){
    sort(src.begin(),src.end(),std::less<int>());
}

int main()
{
    vector<int> vec({1,212,3,24});
    cout<<getMaxValue(vec)<<endl;
    sortValue(vec);
    for (int i = 0; i < vec.size(); ++i) {
        cout<<vec[i]<<endl;
    }
    return 0;
}

