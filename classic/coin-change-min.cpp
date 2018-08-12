#include <bits/stdc++.h>

#define MAXN 1001
#define MAXV 100001
#define INF INT_MAX-1

using namespace std;

int n, v,val[MAXN], memo[MAXV];

int solve(int value){
    if (value == 0)
        return 0;
    if (value < 0)
        return INF;
    if (memo[value] != -1)
        return memo[value];
    int best=INF;
    for(int i = 0; i < n; ++i)
        best=min(best,1+solve(value-val[i]));
    return memo[value] = best;
}

int main(){
    cin>>n;
    memset(memo,-1,sizeof memo);
    for(int i = 0; i < n; ++i){
        cin>>val[i];
    }
    cin>>v;
    cout<<solve(v)<<endl;

    return 0;
}