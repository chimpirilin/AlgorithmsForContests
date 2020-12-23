const int MAXN=100002;

int n;
int v[MAXN];

//1-indexed!
struct Lazy{
	int tree[MAXN*4];
	bool marked[MAXN*4];
	void build(int node, int start, int end){
		if(start==end){
			tree[node]=v[start];
			return;
		}
		int mid=(start+end)>>1;
		build(node*2,start,mid);
		build(node*2+1,mid+1,end);
		tree[node]=0;
		marked[node]=false;
	}
	
	void update(int node, int start,int end,int l,int r,int val){
		if(start>r||end<l){
			return;
		}
		if(start>=l&&end<=r){
			tree[node]=val;
			marked[node]=true;
			return;
		}
		if(marked[node]){
			tree[node*2]=tree[node*2+1]=tree[node];
			marked[node*2]=marked[node*2+1]=true;
			marked[node]=false;
		}
		int mid=(start+end)>>1;
		update(node*2,start,mid,l,r,val);
		update(node*2+1,mid+1,end,l,r,val);
	}
	
	int query(int node,int start,int end,int pos){
		if(start==end){
			return tree[node];
		}
		if(marked[node]){
			return tree[node];
		}
		int mid=(start+end)>>1;
		if(pos<=mid){
			return query(node*2,start,mid,pos);
		}else{
			return query(node*2+1,mid+1,end,pos);
		}
	}
};

int main(){
	cin>>n;
	for(int i=0; i<n;++i){
		cin>>v[i+1];
	}
	Lazy st;
	st.build(1,1,n);
	int l,r,x,q;
	cin>>q;
	while(q--){
		cin>>l>>r>>x;
		st.update(1,1,n,l,r,x);
	}
	
	for(int i=0; i<n;++i){
		cout<<st.query(1,1,n,i+1)<<" ";
	}
	cout<<endl;
	return 0;
}
