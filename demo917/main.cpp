#include <iostream>
#include <math.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<double> string2Vector(const string src);
vector<string> split(string str,string pattern);
double getMaxValue(vector<double> vecA,vector<double> vecB);
double getSorce(vector<double> src,double m);
bool isBig(double x,double y){
    return x<y;
}

int main()
{
    int a;
    int b;
    cin>>a;
    cin>>b;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    return 0;

    int n=100000;
    char* stra=new char[n];
    char* strb=new char[n];
    cin.getline(stra,n);
    cin.getline(strb,n);

    vector<double> veca;
    vector<double> vecb;
    veca=string2Vector(stra);
    vecb=string2Vector(strb);

    cout<<getMaxValue(veca,vecb);
    return 0;
}
vector<double> string2Vector(const string src){
    vector<double> record;
    vector<string> strs;
    strs=split(src," ");
    for (int i = 0; i < (int)strs.size(); ++i) {
        record.push_back(atof(strs.at(i).c_str()));
    }
    return record;
}


double getMaxValue(vector<double> vecA,vector<double> vecB){
    vector<double> A(vecA.begin()+1,vecA.end());
    vector<double> B(vecB.begin()+1,vecB.end());
    sort(A.begin(),A.end(),isBig);
    sort(B.begin(),B.end(),isBig);

    double minValue=(A[0]<B[0])?A[0]:B[0];
    double maxValue=(*(A.end()-1)>*(B.end()-1))?*(A.end()-1):*(B.end()-1);

    double tmp=0;
    for (int i = minValue; i < maxValue; ++i) {
        double x=getSorce(A,i)-getSorce(B,i);
        if (x>tmp) {
            tmp=x;
        }
    }
    return tmp;
}
double getSorce(vector<double> src,double m){
    double value=0;
    int n=src.size();
    for (int i = 0; i < n; ++i) {
        if (src[i]<m) {
            value+=2;
        }else {
            value+=3;
        }
    }
    return value;
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
