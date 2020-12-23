constexpr int tam=300000;
constexpr int inf=(int)1e9;

//set to ll if needed.
vii adl[tam+10];
int dist[tam];
int parent[tam+10];

void dijkstra(int source){
    f(tam) dist[i]=inf;
	dist[source]=0;
    //Be careful with overflow!
    //pair<ll,int> would avoid overflow in case weights are large
	priority_queue<ii,vector<ii>,greater<ii> > pq;
	pq.push({0,source});
	while(!pq.empty()){
		auto front=pq.top();
		pq.pop();
		auto d=front.ff;
		auto u=front.ss;
		if(d>dist[u]) continue;
		for(int i=0; i<sz(adl[u]);++i){
			auto v=adl[u][i];
			if(dist[u]+v.ss<dist[v.ff]){
				dist[v.ff]=dist[u]+v.ss;
				pq.push({dist[v.ff],v.ff});
				parent[v.ff]=u;
			}
		}
	}
}

void path(int node, int target){
	if(node==target){
		cout<<node<< " ";
		return;
	}
	path(parent[node],target);
	cout<<node<< " ";
}

int main(){
	ios::sync_with_stdio(false);
	int v,e;
	cin>>v>>e;
	for(int i=0; i<e;++i){
		int a,b,c;
		cin>>a>>b>>c;
		adl[a].pb({b,c});
	}
	dijkstra(1);
    cout<<dist[v]<<endl;
	path(v,1);
	

	return 0;
}
