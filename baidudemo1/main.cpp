#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
void solve(double m,double n){
    double sumValue=0;
    while(n!=0){
        sumValue+=m;
        m=sqrt(m);
        --n;
    }
    cout<<fixed<<setprecision(2)<<sumValue<<endl;
}

int main()
{
    double n=0,m=0;
    while (cin>>n>>m) {
        solve(n,m);
    }
    return 0;
}

