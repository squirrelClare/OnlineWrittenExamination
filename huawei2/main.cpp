#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
//将整数转化为向量
vector<int> value2Vector(string const src);
void show(vector<int> const src);
//整数相乘并返回结果
string times(const string lhs, const string rhs);
//将向量规范化，即每个元素大小不能超过9
vector<int> vectorFormat(vector<int> src);
//将向量的每个元素合并为字符串
string cv2String(vector<int> const src);

void solute();
int main()
{
    solute();
    return 0;
}
vector<int> vectorFormat(vector<int> src){
    int n=src.size();
    int tag=0;
    int tmp=0;

    for (int i = 0; i < n; ++i) {
        tag=i;
        tmp=src[i]/10;
        src[i]=src[i]%10;

        while (tmp!=0) {
            tag++;
            src[tag]+=tmp%10;
            tmp=tmp/10;
        }
    }

    return src;
}
string cv2String(vector<int> const src){
    stringstream ss;
    string str;
    int tag=0;

    for (int i = src.size()-1; i>=0; --i) {
        if (tag==0&&src[i]==0) {
            continue;
        }else {
            tag=1;
        }
        ss.str("");
        ss<<src[i];
        ss.flush();
        str+=ss.str();
    }
    return str;
}

string times(string const lhs,string const rhs){
    vector<int> vecL(value2Vector(lhs));
    vector<int> vecR(value2Vector(rhs));
    int lenL=vecL.size();
    int lenR=vecR.size();

    vector<int> result((lenL-1)+(lenR-1)+5,0);
    for (int i = 0; i < lenL; ++i) {
        for (int j = 0; j < lenR; ++j) {
            result[i+j]+=vecL[i]*vecR[j];
        }
    }
    result=vectorFormat(result);
    return cv2String(result);
}
vector<int> value2Vector(string const src){
    stringstream ss;
    int n=src.size();
    vector<int> record(n,0);
    int tmp=0;
    int k=0;
    for (int i = n-1; i >=0; --i) {
        sscanf(src.substr(i,1).c_str(),"%d",&tmp);
        record[k++]=tmp;
    }
    return record;
}

void show(vector<int> const src){
    int n=src.size();
    for (int i = 0; i < n; ++i) {
        cout<<src[i]<<' ';
    }
    cout<<'\n';
}
void solute(){
    string lhs="";
    string rhs="";
    cin>>lhs>>rhs;
    cout<<times(lhs,rhs)<<endl;
}
