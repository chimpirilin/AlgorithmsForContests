#include <bits/stdc++.h>
#define maxn 101
#define maxk 101
using namespace std;

int memo[maxn][maxk];

int solve(int n, int k){
    if(k==1) return 1;
    if(memo[n][k]!=-1) return memo[n][k];
    int ways=0;
    for(int i = 0; i <=n; ++i){
        ways=ways+solve(n-i,k-1);
    }
    return memo[n][k]=ways;
}

int main(){
    int n,k;
    cin>>n>>k;
    memset(memo,-1,sizeof memo);
    cout<<solve(n,k)<<endl;
    return 0;
}