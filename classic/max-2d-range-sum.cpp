#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;
    int a[n][m];
    cin>>n>>m;
    int ans=-1e9;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin>>a[n][m];
            if(i>0)
                a[n][m]+=a[n-1][m];
            if(j>0)
                a[n][m]+=a[n][m-1];
            if(i>0&&j>0)
                a[n][m]-=a[n-1][m-1];

            //didn't finish the code...
        }
    }

    return 0;
}