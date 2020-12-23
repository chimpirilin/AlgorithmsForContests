#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
const int maxn=100005;
typedef pair<int,int> ii;

int v[maxn];

struct SegmentTree{
	int n;
	int tree[4*maxn];
	SegmentTree(int nn):n(nn){}
	
	void build(int node, int start, int end){
		if(start==end){
			tree[node]=0;
			if(v[start]==0)
				tree[node]=1;
			return;
		}
		int mid=(start+end)>>1;
		build(node*2,start,mid);
		build(node*2+1,mid+1,end);
		tree[node]=tree[node*2]+tree[node*2+1];
	}
	
	void update(int node, int start, int end, int idx, int val){
		if(start==end){
			tree[node]=0;
			if(val==0){
				tree[node]=1;
			}
			return;
		}
		int mid=(start+end)>>1;
		if(idx<=mid){
			update(node*2,start,mid,idx,val);
		}else{
			update(node*2+1,mid+1,end,idx,val);
		}
		tree[node]=tree[node*2]+tree[node*2+1];
	}
	
	int query(int node,int start, int end, int l, int r){
		if(start>l||end<r){
			return 0;
		}
		if(start>=l&&end<=r){
			return tree[node];
		}
		int mid=(start+end)>>1;
		return query(node*2,start,mid,l,r)+query(node*2+1,mid+1,end,l,r);
	}
	
	int kthZero(int node,int start,int end,int k){
		if(tree[node]<k){
			return -1;
		}
		if(start==end){
			return start;
		}
		int mid=(start+end)>>1;
		if(k<=tree[node*2]){
			return kthZero(node*2,start,mid,k);
		}
		return kthZero(node*2+1,mid+1,end,k-tree[node*2]);
	}
};

int main(){
	int n;cin>>n;
	for(int i=0; i<n;++i){
		cin>>v[i+1];
	}
	SegmentTree st(n);
	st.build(1,1,n);
	cout<<st.query(1,1,n,1,n);cout<<endl;
	cout<<st.kthZero(1,1,n,1);cout<<endl;
	st.update(1,1,n,1,0);
	cout<<st.query(1,1,n,1,n);cout<<endl;
	cout<<st.kthZero(1,1,n,1);cout<<endl;
	return 0;
}
