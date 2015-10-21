#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;
vector<std::string> split(string str,string pattern)
{
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

int sum(vector<int> vec){
    int sum=0;
    for (int i = 0; i < vec.size(); ++i) {
        sum+=vec[i];
    }
    return sum;
}

vector<int> solve(){
    char a[1000];
    cin.getline(a,1000);
    string str(a);

    vector<string> vec;
    vec=split(str," ");
    vector<int> vec1;
    for (int i = 0; i < vec.size(); ++i) {
        vec1.push_back(atoi(vec[i].c_str()));
    }
    for (int i = vec1.size(); i >=0; --i) {
        for (int j = 0; j <=vec1.size()-i; ++j) {
            vector<int> tmpVec;
            for (int var = j; var < j+i; ++var) {
                tmpVec.push_back(vec1[var]);
            }

            if (sum(tmpVec)==0) {
                return tmpVec;
            }
        }
    }
}

int main()
{
    vector<int> vec1;
    vec1=solve();

    for (int i = 0; i < vec1.size(); ++i) {
        cout<<vec1[i];
        if (i!=vec1.size()-1) {
            cout<<" ";
        }else{
            cout<<endl;

        }
    }
    return 0;
}

