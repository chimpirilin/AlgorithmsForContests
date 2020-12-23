vi adl[tam+10];
int cnt[tam+10];
bool visited[tam+10];
int V,E;

//toposort code here

//Run toposort before using it
void numberofpaths(int source){
	for(int i=0; i<V;++i){
		cnt[i]=0;
	}
	cnt[source]=1;
	for(int i=((int)ts.sz)-1; i>=0;--i){
		int u=ts[i];
		for(int j=0; j<(int)adl[u].sz;++j){
			auto v=adl[u][j];
			cnt[v]+=cnt[u];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin>>V>>E;
	for(int i=0; i<E;++i){
		int a,b;
		cin>>a>>b;
		adl[a].pb(b);
	}
	mem(visited,false);
	for(int i=0; i<V;++i){
		if(!visited[i]){
			topo(i);
		}
	}
	int source;cin>>source;
	cerr<<source;cerr<<endl;
	numberofpaths(source);
	
	for(int i=0; i<V;++i){
		cout<<"Number of path that leads to "<<i<<",starting from "<<source<<": "<<cnt[i];cout<<endl;
	}
	return 0;
}

