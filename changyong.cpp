
//字符串分割
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

//最小值
int getMinValue(vector<int> src){
    int tmp=10000;
    size_t n=src.size();
    for (size_t i = 0; i < n; ++i) {
        if (src[i]<tmp) {
            tmp=src[i];
        }
    }
    return tmp;
}
//最大值
int getMaxValue(vector<int> src){
    int tmp=0;
    size_t n=src.size();
    for (size_t i = 0; i < n; ++i) {
        if (src[i]>tmp) {
            tmp=src[i];
        }
    }
    return tmp;
}

