#include <bits/stdc++.h>

#define MAXN 1001
#define MAXV 1001

using namespace std;

int n, val[MAXN], dp[MAXN][MAXV];

int solve(int type, int value) {
    if (value == 0)
        return 1;
    if (value < 0 || type == n)
        return 0;
    if (dp[type][value] != -1)
        return dp[type][value];
    return dp[type][value] = solve(type + 1, value) + solve(type, value - val[type]);
}

int main(){
    cin>>n;
    memset(dp,-1,sizeof dp);
    for(int i = 0; i < n; ++i){
        cin>>val[i];
    }

    int v;
    cin>>v;
    cout<<solve(0,v)<<endl;

    return 0;
}