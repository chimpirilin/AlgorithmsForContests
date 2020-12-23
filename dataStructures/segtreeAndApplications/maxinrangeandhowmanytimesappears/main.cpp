#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef pair<int,int> ii;

const int maxn=100005;
int a[maxn];

struct SegmentTree{
	SegmentTree(int nn):n(nn){}
	int n;
	ii tree[4*maxn];
	
	ii combine(ii x, ii y){
		if(x.ff>y.ff){
			return x;
		}
		if(y.ff>x.ff){
			return y;
		}
		return ii(x.ff, x.ss+y.ss);
	}
	void build(int node, int start, int end){
		if(start==end){
			tree[node]=ii(a[start],1);
			return;
		}
		int mid=(start+end)>>1;
		build(node*2,start,mid);
		build(node*2+1,mid+1,end);
		tree[node]=combine(tree[node*2],tree[node*2+1]);
	}
	
	void update(int node, int index, int val, int start, int end){
		if(start==end){
			tree[node]=ii(val,1);
			a[index]=val;
			return;
		}
		int mid=(start+end)>>1;
		if(index<=mid){
			update(node*2,index,val,start,mid);
		}else{
			update(node*2+1,index,val,mid+1,end);
		}
		tree[node]=combine(tree[node*2],tree[node*2+1]);
	}
	
	ii query(int node, int start, int end, int l, int r){
		if(end<l || start>r){
			return ii(-100000000,0);
		}
		if(start>=l&&end<=r){
			return tree[node];
		}
		int mid=(start+end)>>1;
		query(node*2,start,mid,l,r);
		query(node*2+1,mid+1,end,l,r);
		return tree[node]=combine(tree[node*2],tree[node*2+1]);
	}
};

int  main(){
	int n;
	cin>>n;
	for(int i=0; i<n;++i){
		cin>>a[i+1];
	}
	SegmentTree st(n);
	st.build(1,1,n);
	auto x=st.query(1,1,n,1,n);
	cout<<x.ff<<" "<<x.ss;cout<<endl;
	return 0;
}
