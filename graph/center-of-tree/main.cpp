const int tam=5000;
const int inf=(int)1e9;

vii adl[tam+10];
int n;
int diameter;
void bfs(int source, int *dist){
	for(int i=1; i<=n;++i)
		dist[i]=inf;
	queue<int> q;q.push(source);
	dist[source]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0; i<(int)adl[u].size();++i){
			ii v=adl[u][i];
			if(dist[v.ff]==inf){
				dist[v.ff]=dist[u]+v.ss;
				q.push(v.ff);
			}
		}
	}
}

int distance0[tam+10];
int deepest1,deepest2;
bool tmp;
int d;
int center1,center2;

void dfs(int node,int target){
	for(int i=0; i<(int)adl[node].size();++i){
		auto v=adl[node][i];
		if(distance0[v.ff]!=-1) continue;
		distance0[v.ff]=distance0[node]+1;
		if(v.ff==target){
			tmp=true;
			return;
		}
		dfs(v.ff,target);
		if(tmp){
			++d;
			if(d==diameter/2){
				center1=v.ff;
			}else if(d==(diameter/2)+1){
				center2=v.ff;
			}
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);    
	int distance1[tam+10];
	int distance2[tam+10];
	bfs(1,distance1); //From random node
	int cur=-1;
	for(int i=1; i<=n;++i){
		if(distance1[i]>cur){
			cur=distance1[i];
			deepest1=i;
		}
	}
	bfs(deepest1,distance1); //From the deepest node found in the last bfs
	cur=-1;
	for(int i=1; i<=n;++i){
		if(distance1[i]>cur){
			cur=distance1[i];
			deepest2=i;
		}
	}
	bfs(deepest2,distance2);
	
	diameter=distance2[deepest1];
	memset(distance0,-1,sizeof distance0);
	distance0[deepest1]=0;
	d=0;
	tmp=false;
	dfs(deepest1,deepest2);
	//if diameter is odd then there are 2 centers otherwise there is only one
	return 0;
}
