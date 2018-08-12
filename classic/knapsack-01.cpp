#include <bits/stdc++.h>
using namespace std;
//Set the numbers for the problem
#define MAX_N 1010
#define MAX_W 40

int n, V[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];

int solve(int id, int w){
    if (id == n||w == 0)
        return 0;
    if (memo[id][w] != -1)
        return memo[id][w];
    if (W[id] > w)
        return memo[id][w] = solve(id + 1, w);
    return memo[id][w] = max(solve(id + 1, w), V[id] + solve(id + 1, w - W[id]));
}

int main(){
    cin>>n;
    for(int i = 0; i < n ; ++i){
        cin>>V[i]>>W[i];
    }
    int cap;
    cin>>cap;
    memset(memo, -1, sizeof memo);
    cout<<solve(0,cap);
    cout<<endl;
}