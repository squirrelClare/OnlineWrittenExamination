#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n=0;
    cin>>n;
    vector<vector<int> > vec(n,vector<int>(n,0));
    int tag=n-1;
    int r=0,c=tag;


    int dis=0;
    if (n%2==0) {
        dis=2;
    }else{
        dis=1;
    }

    int tmp=n-1;

    int k=1;
    while (vec[r][c]==0) {
        for (int i = 0; i < tmp; ++i) {
            vec[r++][c]=k++;
        }
        for (int i = 0; i < tmp; ++i) {
            vec[r][c--]=k++;
        }
        for (int i = 0; i < tmp; ++i) {
            vec[r--][c]=k++;
        }
        for (int i = 0; i < tmp; ++i) {
            if (i!=tmp-1) {
               vec[r][c++]=k++;
            }else{
               vec[r++][c]=k++;
            }

        }
        if (r==c) {
            vec[r][c]=k;
            break;
        }
        tmp-=2;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j!=n-1) {
                cout<<vec[i][j]<<" ";
            }else{
                cout<<vec[i][j]<<endl;
            }

        }
    }
}

int main()
{
    solve();
    return 0;
}

