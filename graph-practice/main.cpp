#include <bits/stdc++.h>

using namespace std;

    list<int> cyc;


void solve(list<int>::iterator i , int u,int cnt){
    if(cnt==5) return;
    solve(cyc.insert(i,u),u+1,cnt+1);
}

int main(){
    cyc.clear();
    solve(cyc.begin(),1,0);
    for(auto item : cyc){
        cout<<item<<"->";
    }
    return 0;
}