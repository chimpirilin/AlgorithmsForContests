#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vii vector<pii>
#define pb push_back

const int tam=1000;
vii adl[tam];
bool visited[tam];


void dfs(int v){
    visited[v]=true;
    cout<<v<<endl;
    for(int i=0;i<adl[v].size();++i){
        if(!visited[adl[v][i].first])
            dfs(adl[v][i].first);
    }
}

void add(int a,int b){
    adl[a].pb({b,1});
    adl[b].pb({a,1});
}

int main(){
    int start;
    memset(visited,false,sizeof visited);
    int sz;cin>>sz;while(sz--){
        int a, b;cin>>a>>b;add(a,b);
        start=a;
    }
    dfs(start);
    return 0;
}
