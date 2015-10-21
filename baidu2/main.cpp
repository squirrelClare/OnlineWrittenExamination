#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

double round(double r)
{

return (r > 0.0)?floor(r + 0.5) : ceil(r - 0.5);

}


void getValue(int n,int m,int x,int y,int t){
    x--;
    y--;

    double ss=0;
    vector<vector<double> > rec(n,vector<double>(m,0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>rec[i][j];
            ss+=rec[i][j];
        }
    }
    double cc=rec[x][y];
    ss/=(m*n);

    double a=0,b=0;
    for (int i = 1; i <= t; ++i) {
        a+=ss*pow(1-ss,i-1);
        b+=cc*pow(1-cc,i-1);
    }

    if (a==b) {
        cout<<"equal"<<endl;
        cout<<setiosflags(ios::fixed)<<setprecision(4)<<round(a*10000)/10000<<endl;
    }else {
        if (a>b) {
            cout<<"ss"<<endl<<setiosflags(ios::fixed)<<setprecision(4)<<round(a*10000)/10000<<endl;
        }
        else {
            cout<<"cc"<<endl<<setiosflags(ios::fixed)<<setprecision(4)<<round(b*10000)/10000<<endl;
        }
    }
}

int main()
{
    int n=0,m=0,x=0,y=0,t=0;
    while (cin>>n>>m>>x>>y>>t) {
        getValue(n,m,x,y,t);
    }

    return 0;
}

