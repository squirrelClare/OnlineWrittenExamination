#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Node{
public:
    int l;
    int m;
    int r;
};

bool less1(Node x,Node y){
    return x.r<y.r;
}
bool less2(Node x,Node y){
    return x.m<y.m;
}
bool less3(Node x,Node y){
    return x.l<y.l;
}
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

Node string2Node(string str){
    vector<string> vec;
    Node node;
    vec=split(str,".");

    node.l=atoi(vec[0].c_str());
    node.m=atoi(vec[1].c_str());
    if (vec.size()!=3) {
        node.r=0;
    }else{
        node.r=atoi(vec[2].c_str());
    }
    return node;
}

void solve(){
    vector<Node> vec;
    int n=0;
    string tmpStr;
    Node tmpNode;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>tmpStr;
        tmpNode=string2Node(tmpStr);
        if (tmpNode.m%2==0) {
            vec.push_back(tmpNode);
        }
    }
    if (vec.size()==0) {
        cout<<"no stable availab"<<endl;
    }
    sort(vec.begin(),vec.end(),less1);
    sort(vec.begin(),vec.end(),less2);
    sort(vec.begin(),vec.end(),less3);
    tmpNode=*(vec.end()-1);

    if (tmpNode.r==0) {
        cout<<tmpNode.l<<"."<<tmpNode.m<<endl;
    }else{
        cout<<tmpNode.l<<"."<<tmpNode.m<<"."<<tmpNode.r;
    }

}

int main()
{
    solve();
    return 0;
}

