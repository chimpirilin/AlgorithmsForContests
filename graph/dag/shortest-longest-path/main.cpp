const int tam=1000;
const int inf=(int) 1e9;

vii adl[tam+10];
int parent[tam+10];
int dist[tam+10];
bool visited[tam+10];
int V,E;

//toposort code here

//Run toposort before using it
void sssp(int source){
	for(int i=0; i<V;++i){
		dist[i]=inf;
	}
	
	dist[source]=0;
	
	for(int i=((int)ts.sz)-1; i>=0;--i){
		int u=ts[i];
		for(int j=0; j<(int)adl[u].sz;++j){
			auto v=adl[u][j];
			if(dist[v.ff]>dist[u]+v.ss){
				dist[v.ff]=dist[u]+v.ss;
				parent[v.ff]=u;
			}
		}
	}
}

void printpath(int source,int target){
	if(source==target){
		cout<<source<< " ";
		return;
	}
	printpath(parent[source],target);
	cout<<source<< " ";
}

int main(){
	ios::sync_with_stdio(false);
	cin>>V>>E;
	for(int i=0; i<E;++i){
		int a,b,c;
		cin>>a>>b>>c;
		adl[a].pb({b,c});
		//adl[a].pb({b,-c}); //For longest path
	}
	mem(visited,false);
	for(int i=0; i<V;++i){
		if(!visited[i]){
			topo(i);
		}
	}
	int source;
	cin>>source;
	sssp(source);
	for(int i=0; i<V;++i){
		cout<<"Shortest path from "<<source<< " to "<<i<<":"<<dist[i];cout<<endl;
		printpath(i,source);
		cout<<endl;
	}
	
	return 0;
}

