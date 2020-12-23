const int tam=200009;
const int level=18;
 
int up[tam][level+1];
vi adl[tam];
int tin[tam];
int tout[tam];
int timer;
 
void dfs(int node,int p){
    tin[node]=++timer;
    up[node][0]=p;
    for(int i=1;i<=level;++i) up[node][i]=up[up[node][i-1]][i-1];
    for(auto x:adl[node]){
        if(x==p) continue;
        dfs(x,node);
    }
    tout[node]=++timer;
}
 
bool isAncestor(int u,int v){
    if(u==0) return 1;
    return tin[u]<=tin[v]&&tout[u]>=tin[v];
}
 
int lca(int u,int v){
    if(isAncestor(u,v)) return u;
    if(isAncestor(v,u)) return v;
    for(int i=level;i>=0;--i){
        if(isAncestor(up[u][i],v)) continue;
        u=up[u][i];
    }
    return up[u][0];
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q,a,b;
	cin>>n>>q;
	for(int i=2;i<=n;++i) cin>>a,adl[i].push_back(a),adl[a].push_back(i);
	dfs(1,0);
	while(q--){
		cin>>a>>b;
		int res=lca(a,b);
		cout<<res<<endl;
	}
	return 0;
}
