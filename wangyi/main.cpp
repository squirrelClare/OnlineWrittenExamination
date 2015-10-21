#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
bool countLeft(char c){
    return c=='{';
}
bool countRight(char c){
    return c=='}';
}
vector<int> findKey(string src,string key){
    int n=src.size();   //源字符串长度
    int m=key.size();   //关键字长度
    size_t oldTag=0;  //旧起始位置
    size_t newTag=0;  //新起始位置
    int numOfLeft=0;      //左括号个数
    int numOfRight=0;     //右括号个数

    set<int> result;     //存储结果
    string tmpStr="";     //临时字符串
    while ((newTag=src.find(key,oldTag))!=string::npos) {
        tmpStr=src.substr(oldTag,newTag-oldTag);
        //计算左大括号个数
        numOfLeft+=count_if(tmpStr.begin(),tmpStr.end(),countLeft);
        //计算右大括号个数
        numOfRight+=count_if(tmpStr.begin(),tmpStr.end(),countRight);
        result.insert(numOfLeft-numOfRight+1);
        oldTag=newTag+m;

    }
    if (result.size()==0) {
        result.insert(-1);
    }
    return vector<int>(result.begin(),result.end());
}

int main()
{
    string src;
    string key;
    vector<int> s;
//    s=findKey("Fruit{apple{shape,color},orange{color,price},color}","color");
//    int n=s.size();
//    for (int i=0;i<n;++i) {
//        if (i!=(n-1)) {
//          cout<<s[i]<<",";
//        }else {
//            cout<<s[i]<<endl;
//        }
//    }


    for (int j = 0; j < 100; ++j) {
        if(cin>>src>>key) {
            s=findKey(src,key);
            int n=s.size();
            for (int i=0;i<n;++i) {
                if (i!=(n-1)) {
                  cout<<s[i]<<",";
                }else {
                    cout<<s[i]<<endl;
                }
            }
        }
    }

    return 0;
}

