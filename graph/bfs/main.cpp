int dist[tam+10];
vi adl[tam+10]; 
int parent[tam+10];
int start;

void bfs(int source){
	for(int i=0; i<tam;++i){
		dist[i]=inf;
	}
	queue<int> q;q.push(source);
	dist[source]=0;
	while(!q.empty()){
		auto u=q.front();q.pop();
		for(int i=0; i<sz(adl[u]);++i){
			auto v=adl[u][i];
			if(dist[v]==inf){
				dist[v]=dist[u]+1;
				q.push(v);
				parent[v]=u;
			}
		}
	}
}

void printpath(int node){
	if(node==start){
		cout<<node<<" ";
		return;
	}
	printpath(parent[node]);
	cout<<node<< " ";
}

void bfs01(int source){
	deque<int> q;q.push_front(source);
	dist[source]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop_front();
		for(int i=0; i<sz(adl[u]);++i){
			auto v=adl[u][i];
			if(dist[u]+v.ss<dist[v]){
				dist[v]=dist[u]+v.ss;
				if(v.ss==1){
					q.push_back(v);
				}else{
					q.push_front(v);
				}				
			}
		}
	}
}

void add(int a,int b){
    adl[a].pb({b,1});
    adl[b].pb({a,1});
}

int main(){
	ios::sync_with_stdio(false);
	start=5;
    int n;cin>>n;
    while(n--){
        int a, b;cin>>a>>b;
        adl[a].pb(b);
        adl[b].pb(a);
        //~ start=a;
    }
    bfs(start);
    printpath(7);
	return 0;
}
