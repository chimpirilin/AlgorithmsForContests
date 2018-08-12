#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vii vector<pii>
#define vi vector<int>
#define tam 1000
#define fff first
#define sss second

vii adl[tam];
list<int> tour;

int eulerPathStart,eulerPathEnd;

//Euler path/tour on a undirected graph
bool existEulerTour(){
    for(int i=0;i<tam;++i){
        if((int)adl[i].size()%2!=0) 
            return false;
    }

    return true;
}

bool existEulerPath(){
    int cnt=0;
    for(int i=0;i<tam;++i){
        if((int)adl[i].size()%2!=0){
            ++cnt;
            if(eulerPathStart<0)
                eulerPathStart=i;
            else
                eulerPathEnd=i;
        }
    }

    return (cnt==2||cnt==0);
}

void insert(int u, int v){
    adl[u].push_back({v,1});
    if(v!=u)
        adl[v].push_back({u,1});
}

//Store an euler tour (starting from u) in linked list
void eulerTour(list<int>::iterator i, int u){
    for(int j=0;j<adl[u].size();++j){
        pii &v=adl[u][j];
        if(v.sss){
            v.sss=0;
            for(int k = 0; k < adl[v.first].size(); ++k){
                pii &uu=adl[v.first][k];
                if(uu.fff==u&&uu.sss){
                    uu.sss=0;
                    break;
                }
            }
            eulerTour(tour.insert(i,u),v.first);
        }
    }
}

int main(){
    int eulerTourStart=0;
    int t;cin>>t;while(t--){
        int  a,b;cin>>a>>b;
        eulerTourStart=a;
        insert(a,b);
    }
    eulerPathStart=INT_MIN;
    eulerPathEnd=INT_MIN;

    if(existEulerTour()){
        eulerTour(tour.begin(),eulerTourStart);
        tour.insert(tour.begin(),eulerTourStart);
        cout<<"Euler tour!"<<endl;
        for(auto i = tour.rbegin(); i != tour.rend(); ++i){
            cout<<*i;
            if(next(i)!=tour.rend())
                cout<<"->";
        }
        //cout<<eulerTourStart<<endl;
    
    
    }else if(existEulerPath()){
        cout<<"Euler path!"<<endl;
        eulerTour(tour.begin(),eulerPathStart);
        tour.insert(tour.begin(),eulerPathEnd);
        for(auto i = tour.rbegin(); i != tour.rend(); ++i){
            cout<<*i;
            if(next(i)!=tour.rend())
                cout<<"->";
        }

        //cout<<eulerPathEnd<<endl;
    }else cout<<"There is not an euler path/tour :("<<endl;
    return 0;
}