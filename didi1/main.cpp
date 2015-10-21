#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

vector<std::string> split(string str,string pattern)
{
    int i=0;
    int j=0;
    for (i = 0; i < str.size(); ++i) {
        if (str.substr(i,1)!=" ") {
            break;
        }
    }

    for (j = str.size()-1; j>=0 ; --j) {
        if (str.substr(j,1)!=" ") {
            break;
        }
    }
    str=str.substr(i,i-j+1);
    string::size_type pos;
    vector<string> result;
    str+=pattern;
    size_t size=str.size();

    for(int i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
        std::string s=str.substr(i,pos-i);
        result.push_back(s);
        i=pos+pattern.size()-1;
    }
  }
  return result;
}


void solve(){
    char a[1000];
    cin.getline(a,1000);
    string str(a);
    vector<string> rVec;
    rVec=split(str,";");

    vector<vector<int> > vec;

    vector<string> tmp;

    for (int i = 0; i < rVec.size()-1; ++i) {
        tmp=split(rVec.at(i)," ");
        vector<int> tmpVec;
        for (int j = 0; j < tmp.size()-1; ++j) {
            if (tmp[j]!=" ") {
               tmpVec.push_back(atoi(tmp[j].c_str()));
            }
        }
        vec.push_back(tmpVec);
    }

    tmp=split(rVec.at(rVec.size()-1)," ");
    vector<int> tmpVec;
    for (int j = 0; j < tmp.size(); ++j) {
        if (tmp[j]!=" ") {
           tmpVec.push_back(atoi(tmp[j].c_str()));
        }

    }
    vec.push_back(tmpVec);


    int nr=vec.size();
    int nc=vec[0].size();

    int sum=-100000;
    for (int i = 0; i < nr-1; ++i) {
        for (int j = 0; j < nc-1; ++j) {
            int tmpSum=vec[i][j]+vec[i][j+1]+vec[i+1][j]+vec[i+1][j+1];
            if (tmpSum>sum) {
                sum=tmpSum;
            }
        }
    }
    cout<<sum<<endl;
}

int main()
{
    solve();
    return 0;
}

