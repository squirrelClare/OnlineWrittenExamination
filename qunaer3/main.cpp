#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <algorithm>

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
void show(vector<string> vec){
    for (int i = 0; i < vec.size(); ++i) {
        cout<<i<<"   "<<vec[i]<<endl;
    }
}

void solve(){
    int n=0;
    cin>>n;
    cin.get();

    map<string,vector<string> > record;
    vector<string> vec;
    string tmpStr;
    for (int i = 0; i < n; ++i) {
        getline(cin,tmpStr);
        if (vec[2]!=" "&&vec[1]!=" ") {
            vector<string> tmp;
            tmp.push_back(vec[1]);
            tmp.push_back(vec[2]);
            record[vec[0]]=tmp;
        }
    }



    int tag=0;
    for (map<string,vector<string> >::iterator it=record.begin();it!=record.end();++it) {
        string id;
        id=it->first;

        string target=(it->second)[1];
        map<string,vector<string> >::iterator it2;
        while(true){
            for (it2=record.begin();it2!=record.end();++it2){
                string tmp;
                tmp=(it2->second)[0];

                if (tmp.find_first_of(target,0)!=string::npos) {
                    if (it2->first!=id) {
                        target=(it2->second)[1];

                        break;
                    }else{
                        tag++;
                    }
                }
            }
            if (it2==record.end()) {
                break;
            }
        }
    }
    cout<<tag<<endl;

}

int main()
{
    solve();
    return 0;
}

