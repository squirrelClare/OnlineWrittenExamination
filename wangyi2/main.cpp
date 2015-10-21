#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
void getPercent(string src,string dst){
    vector<int> vecDst(dst.size(),0);
    for (int i = 0; i < dst.size(); ++i) {
        vecDst[i]=atoi(dst.substr(i,1).c_str());
    }

    vector<int> vecSrc;
    for (int i = 0; i < src.size(); ++i) {
        char tmp=src[i];
        if ((tmp>='0'&&tmp<='9')||(tmp>='A'&&tmp<='Z')||(tmp>='a'&&tmp<='z')) {
            vecSrc.push_back(1);
        }else{
            vecSrc.push_back(0);
        }
    }

    float sum=0;
    for (int i = 0; i < vecSrc.size(); ++i) {
        sum+=abs(vecSrc[i]-vecDst[i]);
    }
    printf("%.2f%%",(vecSrc.size()-sum)/(float)vecSrc.size()*100);
}

int main()
{
    while (true) {
        string src,dst;
        cin>>src>>dst;
        getPercent(src,dst);
    }
    return 0;
}

