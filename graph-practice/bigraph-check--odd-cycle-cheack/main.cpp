#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vii vector<pii>
#define fff first
#define sss second
#define tam 1000
#define pb push_back

vii adl[tam];
short color[tam];

bool isBipartite(int v, short c){
    color[v]=(c+1)%2;
    for(int i=0;i<adl[v].size();++i){
        cout<< color[adl[v][i].fff]<< " "<<adl[v][i].fff<<endl;
        if(color[adl[v][i].fff]==-1)
            return isBipartite(adl[v][i].fff,color[v]);
        else if(color[adl[v][i].fff]==color[v]) 
            return false;
    }
    return true;
}

void add(int a,int b){
    adl[b].pb({a,1});
    adl[a].pb({b,1});
}

int main(){
    int start=-1;
    int t;cin>>t;while(t--){
        int a,b;
        cin>>a>>b;
        add(a,b);
        start=a;
    }
    memset(color,-1,sizeof color);
    if(isBipartite(start,0))
        cout<<"The graph is bipartite!";
    else
        cout<<"The graph is not bipartite!";
    cout<<endl;
    return 0;
}