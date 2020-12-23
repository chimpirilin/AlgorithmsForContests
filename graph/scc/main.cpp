vi adl[tam];
vi stck;
int low[tam];
int num[tam];
bool visited[tam];
int cnt=0;
map<int,vi> strcc;

void scc(int node){
	low[node]=++cnt;
	num[node]=low[node];
	stck.pb(node);
	visited[node]=true;
	for(int i=0; i<(int)adl[node].sz;++i){
		int v=adl[node][i];
		if(num[v]==-1) scc(v);
		if(visited[v]) low[node]=min(low[v],low[node]);
	}

	if(low[node]==num[node]){
		while(1){
			int v=stck.back();
			stck.pop_back();
			visited[v]=false;
			strcc[node].pb(v);
			if(v==node) break;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int numEdges;cin>>numEdges;
	set<int> edges;
	while(numEdges--){
		int a,b;cin>>a>>b;
		adl[a].pb(b);
		edges.insert(a);
		edges.insert(b);
	}
	mem(num,-1);
	mem(visited,false);
	for(auto item:edges){
		if(num[item]==-1)
			scc(item);
	}
	
	for(auto item:strcc){
		cout<<"Root: "<<item.ff<<endl;
		for(auto item2:item.ss){
			cout<<item2<< " ";
		}
		cout<<endl;
	}
	
	
	
	return 0;
}
