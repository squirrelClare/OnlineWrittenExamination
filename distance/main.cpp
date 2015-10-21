#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>
using namespace std;
std::vector<std::string> split(std::string str,std::string pattern);
vector<vector<double> > inputVects();    //获取多个向量
vector<double> inputVect();     //生成含有四个元素的向量
double dist(const vector<double> src);    //计算距离

template<class T>
void show(const vector<T> vec);    //打印向量内部元素

template<class T>
vector<T> string2Number(vector<string> vec);    //字符转数字

int main()
{
    vector<vector<double> > vecs;
    vecs = inputVects();
    for (int i = 0; i < vecs.size(); ++i) {
        std::cout << dist(vecs.at(i))<<endl;
    }
    return 0;
}


vector<vector<double> > inputVects() {
    vector<vector<double> > vecs;
    vector<double> tmp;
    do {
        tmp = inputVect();
        if (tmp.size() != 0) {
            vecs.push_back(tmp);
        }
    } while (tmp.size() != 0);
    return vecs;
}

vector<double> inputVect() {
    string str;
    getline(cin, str);
    if (str.size() == 0) {
        return vector<double>();
    }
    vector<string> vec;
    vec = split(str, " ");
    return string2Number<double>(vec);
}

double dist(vector<double> const src) {
    double tmp = 0;
    tmp += pow(src[0] - src[1], 2);
    tmp += pow(src[2] - src[3], 2);
    return sqrt(tmp);
}
template<class T>
void show(vector<T> const vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec.at(i) << '\t';
    }
    cout<< '\n';
}
//字符串分割函数
std::vector<std::string> split(std::string str,std::string pattern)
{
    std::string::size_type pos;
    std::vector<std::string> result;
    str+=pattern;//扩展字符串以方便操作
    int size=str.size();

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
template<class T>
vector<T> string2Number(vector<string> vec) {
    stringstream ss;
    vector<T> values;
    T tmp = 0;
    for (int i = 0; i < vec.size(); ++i) {
        ss << vec[i];
        ss >> tmp;
        ss.clear();
        values.push_back(tmp);
    }
    return values;
}
