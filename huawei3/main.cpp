#include <iostream>
#include <vector>
using namespace std;
//打印向量中的内容
void show(vector<string> const src);
//获取指定字符串中的组合
vector<string> getElement(string src,int n);
//将vec中的每一个元素前面加上str
void merge(string str,vector<string> &vec);

int solute();
int main()
{
    solute();
    return 0;
}

void merge(string str,vector<string> &vec){
    int n=vec.size();
    for (int i = 0; i < n; ++i) {
        vec[i]=str+vec[i];
    }
}

vector<string> getElement(string src,int n){
    int len=src.size();
    vector<string> record;
    if(n==1){
        for (int i = 0; i < len; ++i) {
            record.push_back(src.substr(i,1));
        }
    }else{
        vector<string> vec;
        for (int i = 0; i < len; ++i) {
            vec=getElement(src.substr(i+1,len-i-1),n-1);
            merge(src.substr(i,1),vec);
            record.insert(record.end(),vec.begin(),vec.end());
        }
    }
    return record;
}
void show(vector<string> const src){
    int n=src.size();
    for (int i = 0; i < n; ++i) {
        cout<<src[i]<<" ";
    }
    cout<<'\n';
}
int solute(){
    string str="";
    int m;
    cin>>str>>m;
    if ((int)str.size()<m||m==0||str.size()==0) {
        cout<<"ERROR"<<endl;
        return 0;
    }
    show(getElement(str,m));
    return 0;
}
