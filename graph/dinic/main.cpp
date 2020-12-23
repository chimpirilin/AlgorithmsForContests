#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define sz(v) ((int)v.size())
#define INF 1e18

const int MAX = 300;
// Corte minimo: vertices con dist[v]>=0 (del lado de src) VS.  dist[v]==-1 (del lado del dst)
// Para el caso de la red de Bipartite Matching (Sean V1 y V2 los conjuntos mas proximos a src y dst respectivamente):
// Reconstruir matching: para todo v1 en V1 ver las aristas a vertices de V2 con it->f>0, es arista del Matching
// Min Vertex Cover: vertices de V1 con dist[v]==-1 + vertices de V2 con dist[v]>0
// Max Independent Set: tomar los vertices NO tomados por el Min Vertex Cover
// MIS=MCBM
// MVC+MCBM=nodos
// Max Clique: construir la red de G complemento (debe ser bipartito!) y encontrar un Max Independet Set
// Min Edge Cover: tomar las aristas del matching + para todo vertices no cubierto hasta el momento, tomar cualquier arista de el
//Complejidad: 
//Peor caso: O(V^2E)
//Si todas las capacidades son 1: O(min(E^1/2,V^2/3)E)
//Para matching bipartito es: O(sqrt(V)E)

int nodes, src, dst;
int dist[MAX+1], q[MAX+1], work[MAX+1];
struct Edge {
    int to, rev;
    ll f, cap;
    Edge(int to, int rev, ll f, ll cap) : to(to), rev(rev), f(f), cap(cap) {}
};
vector<Edge> G[MAX];
void addEdge(int s, int t, ll cap){
    G[s].pb(Edge(t, sz(G[t]), 0, cap)), G[t].pb(Edge(s, sz(G[s])-1, 0, 0));}
bool dinic_bfs(){
    fill(dist, dist+nodes, -1), dist[src]=0;
    int qt=0; q[qt++]=src;
    for(int qh=0; qh<qt; qh++){
        int u =q[qh];
        for(auto e:G[u]){
            int v=e.to;
            if(dist[v]<0 && e.f < e.cap)
                dist[v]=dist[u]+1, q[qt++]=v;
        }
    }
    return dist[dst]>=0;
}
ll dinic_dfs(int u, ll f){
    if(u==dst) return f;
    for(int &i=work[u]; i<sz(G[u]); i++){
        Edge &e = G[u][i];
        if(e.cap<=e.f) continue;
        int v=e.to;
        if(dist[v]==dist[u]+1){
			ll df=dinic_dfs(v, min(f, e.cap-e.f));
			if(df>0){
				e.f+=df, G[v][e.rev].f-= df;
				return df;
			}
        }
    }
    return 0;
}
ll maxFlow(int _src, int _dst){
    src=_src, dst=_dst;
    ll result=0;
    while(dinic_bfs()){
        fill(work, work+nodes, 0);
        while(ll delta=dinic_dfs(src,INF)){
            result+=delta;
		}
    }
    // todos los nodos con dist[v]!=-1 vs los que tienen dist[v]==-1 forman el min-cut
	return result;
}

void mincut(){
	set<int> s;
	set<int> t;
	for(int i=0; i<nodes;++i){
		if(dist[i]>=0){
			s.insert(i);
		}else{
			t.insert(i);
		}
	}
	cout<<"S";cout<<endl;
	for(auto item:s){
		cout<<item<<" ";
	}
	cout<<endl;
	cout<<"T";cout<<endl;
	for(auto item:t){
		cout<<item<<" ";
	}
	cout<<"Mincut edges: ";cout<<endl;
	//I'm not sure if this is 100% correct but it seems to work quite well!
	for(auto item:s){
		for(auto item2:G[item]){
			if(item2.cap!=0 &&s.find(item2.to)==s.end()){
				cout<<item<<"->"<<item2.to;cout<<endl;
			}
		}
	}
}

int main(){
	int E;
	cin>>E;
	int so,si;
	for(int i=0; i<E;++i){
		int a,b,c;
		cin>>a>>b>>c;
		addEdge(a,b,c);
	}
	nodes=10;
	cin>>so>>si;
	cout<<maxFlow(so,si);
	cout<<endl;
	
	return 0;
}
