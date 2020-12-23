int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	ll a[n+1];
	ll b[n+1];
	map<int,int> rank;
	cin>>n;
	for(int i=0; i<n;++i){
		cin>>a[i];
		b[i]=a[i];
		rank[b[i]]=-1;
	}
	sort(b,b+n);
	int nx=0;
	for(int i=0; i<n;++i){
		if(rank[b[i]]==-1){
			rank[b[i]]=++nx;
		}
	}
	Fenwick tree; //From dataStructures
	tree.init(nx+2);
	int inversions=0;
	for(int i=n-1;i>=0;--i){
		inversions+=tree.sum(rank[a[i]]);
		tree.adjust(rank[a[i]], 1);
	}
	cout<<inversions;	
	return 0;
}
