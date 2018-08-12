#include <bits/stdc++.h>
using namespace std;
//Set the numbers for the problem
#define MAX_N 1010
#define MAX_W 10001
#define INF INT_MAX-1

int n, cap,W[MAX_N], dp[MAX_N][MAX_W], vals[MAX_N][MAX_W],mn;

int solve(int id, int w){
    if (id == n||w == 0)
        return cap-w;
    if (dp[id][w] != -1)
        return dp[id][w];
    if (W[id] > w)
        return dp[id][w] = solve(id + 1, w);
    return dp[id][w] = max(solve(id + 1, w), solve(id + 1, w - W[id]));
}

int main(){
    int t;cin>>t;while(t--){
        cin>>cap;
        cin>>n;
        mn=INF;
        for(int i = 0; i < n ; ++i){
            cin>>W[i];
        }
        memset(dp, -1, sizeof dp);
        auto ans=solve(0,cap,0);
        cerr<<ans.first<<endl;
        if(ans.first== cap)
            cout<<ans.first<< " "<<ans.second<<endl;
        else
            cout<<mn<< " "<<solve(0,mn,0).second<<endl;

    }
}