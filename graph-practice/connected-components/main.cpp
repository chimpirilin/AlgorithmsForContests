#include <bits/stdc++.h>
#define pii pair<int,int>
#define vii vector<pii>
#define pb push_back
#define fff first
#define sss second
#define tam 1000

using namespace std;

bool visited[tam];
vii adl[tam];
void dfs(int v){
    visited[v]=true;
    cout<<v<< " ";
    //rep(i,0,adl[v].size())
    for(int i=0;i<adl[v].size();++i)
        if(!visited[adl[v][i].fff])
            dfs(adl[v][i].fff);
}

void add(int a,int b){
    adl[a].pb({b,1});
    adl[b].pb({a,1});
}

void cc(){
    int cnt=0;
    for(int i=0;i<tam;++i){
        if(!visited[i]&&adl[i].size()>0){
            cout<<"Connected component #"<<++cnt<<": ";
            dfs(i);
            cout<<endl;
        }

    }
}

int main(){
    int t;cin>>t;while(t--){
        int a,b;cin>>a>>b;add(a,b);
    }

    cc();
    return 0;
}
