#include <bits/stdc++.h>
#define MAXN 10000
#define MAXW 10000

using namespace std;

int dp[MAXW];
int val[MAXN];
int w[MAXN];
int cap;
int n;

int solve(int curw){
    if(curw==0) return 0;
    auto &ref=dp[curw];
    if(ref!=-1)return ref;
    int best=0;
    int bsw=0;
    for(int i = 0; i < n; ++i){
        if(curw-w[i]>=0){
            auto ans=solve(curw-w[i])+val[i];
            if(ans>best){
                bsw=curw-w[i];
                best=ans;
            }
            //best=max(best,solve(curw-w[i])+val[i]);
        }
    }
    cerr<<"Best for "<<curw<<"  "<<best<< ", best weight " <<bsw<<endl;
    return ref=best;
}

int main(){
    cin>>n;
    for(int i = 0; i < n; ++i)
        cin>>val[i];
    for(int i = 0; i < n; ++i)
        cin>>w[i];
    cin>>cap;
    memset(dp,-1,sizeof dp);
    cout<<solve(cap)<<endl;
    return 0;
}