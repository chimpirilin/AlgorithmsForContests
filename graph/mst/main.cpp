//Union find code

int E,V;
vector<pair<int, ii> > edgelist;

int mst(){
	int mstCost=0;
	UnionFind UF(V+1); //V+1 if it is from 0 to N otherwise UF(V)
	//~ assert(E==(int)edgelist.sz);
	for(int i=0; i<E;++i){
		auto front=edgelist[i];
		if(!UF.inSameSet(front.ss.ff,front.ss.ss)){
			mstCost+=front.ff;
			UF.unionSet(front.ss.ff,front.ss.ss);
		}
	}
	
	return mstCost;
}

int main(){
	ios::sync_with_stdio(false);
	cin>>V;
	cin>>E;
	int u,v,w;
	for(int i=0; i<E;++i){
		cin>>u>>v>>w;
		edgelist.pb({w,{u,v}});
	}

	sort(edgelist.beg,edgelist.en);
	cout<<mst();cout<<endl;
	
	
	return 0;
}
