#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
//判断是否是字符
bool isChar(char const src);
//删除不是字符的字符
vector<char> trimNotChar(string src);
//统计字符个数
pair<vector<char>,vector<int> > cv2Map(vector<char> src);
//合并并返回结果
string merge(pair<vector<char>,vector<int> > src);

void solute();

int main()
{
    solute();
    return 0;
}


bool isChar(char src){
    if ((src>='a'&&src<='z')||(src>='A'&&src<='Z')){
        return true;
    }
    return false;
}

vector<char> trimNotChar(string src){
    vector<char> record;
    int n=src.size();
    char tmp;
    for (int i=0;i<n;++i){
        tmp=src[i];

        if(isChar(tmp)){
            record.push_back(tmp);
        }
    }
    return record;
}
pair<vector<char>,vector<int> > cv2Map(vector<char> src){
    int n=src.size();
    vector<char> charName;
    vector<int> charNum;

    vector<int> record;
    record.push_back((int)src[0]);
    for (int i = 1; i < n; ++i) {
        record.push_back((int)(src[i]-src[i-1]));
    }

    int count=0;
    for (int i = 0; i < n; ++i) {
        if (record[i]!=0) {
            charNum.push_back(count+1);
            charName.push_back(src[i]);
            count=0;
        }else {
            ++count;
        }
    }
    charNum.push_back(count+1);
    charNum.erase(charNum.begin(),charNum.begin()+1);
    return make_pair<vector<char>,vector<int> >(charName,charNum);
}

string merge(pair<vector<char>,vector<int> > src){
    vector<char> names(src.first);
    vector<int> nums(src.second);
    int n=names.size();
    string p;

    stringstream ss;
    for (int i = 0; i < n; ++i) {
        p+=names[i];
        ss<<nums[i];
        p+=ss.str();
        ss.flush();
        ss.str("");
    }
    return p;
}

void solute(){
    string str="";
    cin>>str;
    vector<char> src(trimNotChar(str));
    pair<vector<char>,vector<int> > tmpPair;

    if (src.size()==0) {
        return;
    }

    tmpPair=cv2Map(src);
    cout<<merge(tmpPair)<<endl;
}
