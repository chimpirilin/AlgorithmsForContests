#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vii vector<pii>
#define vi vector<int>
#define tam 1000


//vector<vii> adl;
vii adl[tam];

//Euler path/tour on a undirected graph
bool existEulerTour(){
    for(int i=0;i<tam;++i){
        if((int)adl[i].size()%2!=0) return false;
    }

    return true;
}

bool existEulerPath(){
    int cnt=0;
    for(int i=0;i<tam;++i){
        if((int)adl[i].size()%2!=0) ++cnt;
    }

    return (cnt==2||cnt==0);
}

void insert(int u, int v){
    adl[u].push_back({v,1});
    adl[v].push_back({u,1});
}


int main(){
    int t;cin>>t;while(t--){
        int  a,b;cin>>a>>b;
        insert(a,b);
    }
    cout<<(existEulerTour()?"There is an euler tour!":"There is not an euler tour :(")<<endl;
    cout<<(existEulerPath()?"There is an euler path!":"There is not an euler path :(")<<endl;

    return 0;
}