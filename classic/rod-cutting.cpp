#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int n;

int rodC(int n, vector<int> &r){
    if(r[n]>=0)
        return r[n];
    int q=0;
    if(n>0){
        q=-1e9;
        for(int i = 1; i <= n; ++i){
            q=max(q,v[i-1]+rodC(n-i,r));
        }
    }

    r[n]=q;
    return q;
}

int main(){
    cin>>n;
    vector<int> r(n+1);
    fill(r.begin(),r.end(),-1);
    for(int i = 0; i < n; ++i){
        int x;
        cin>>x;
        v.push_back(x);
    }

    cout<<rodC(n,r);

    return 0;
}