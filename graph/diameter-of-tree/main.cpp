const int tam=300009;
const int inf=(int)1e9;

vi adl[tam];

void bfs(int source,int &deepest, vi &dist){
	int curmax=-1;
	queue<int> q;q.push(source);
	dist[source]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0; i<sz(adl[u]);++i){
			auto v=adl[u][i];
			if(dist[v]==inf){
				dist[v]=dist[u]+1;
				q.push(v);
				if(dist[v]>curmax){
					curmax=dist[v];
					deepest=v;
				}
			}
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
    int n,a,b;
    cin>>n;
    f(n-1){
        cin>>a>>b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    vi dist(tam,inf);
    int end1,end2;
    bfs(1,end1,dist); //The graph may no contain 1!
    fill(all(dist),inf);
    bfs(end1,end2,dist);
    int diameter=dist[end2];
	return 0;
}


