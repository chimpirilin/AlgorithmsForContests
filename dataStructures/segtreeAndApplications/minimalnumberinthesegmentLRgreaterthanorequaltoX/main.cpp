#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ff first
#define ss second
#define SZ(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define endl '\n'
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=(int)1e9;
const int maxint=0x7f;

const int maxn=1001;
int a[maxn];
int n;

//~ Without modifications
struct SegmentTree{
	vi tree[4*maxn];
	int n;
	SegmentTree(int nn):n(nn){}
	void build(int node, int start, int end){
		if(start==end){
			tree[node]=vi(1,a[start]);
			return;
		}
		int mid=(start+end)>>1;
		build(node*2,start,mid);
		build(node*2+1,mid+1,end);
		merge(all(tree[node*2]),all(tree[node*2+1]), back_inserter(tree[node]));
	}
	
	int query(int node,int start,int end,int l,int r, int x){
		if(start>r||end<l){
			return inf;
		}
		if(start>=l&&end<=r){
			auto tmp=lower_bound(all(tree[node]),x);
			if(tmp==tree[node].end()){
				return inf;
			}
			return *tmp;
		}
		int mid=(start+end)>>1;
		return min(query(node*2,start,mid,l,r,x),query(node*2+1,mid+1,end,l,r,x));
	}
};

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n;++i){
		cin>>a[i+1];
	}
	SegmentTree st(n);
	st.build(1,1,n);
	int q;cin>>q;
	int l,r,x;
	while(q--){
		cin>>l>>r>>x;
		cout<<"The minimal number x in the segment ["<<l<<","<<r<<"]"<<" such that x >= "<<x<<" is: "<<st.query(1,1,n,l,r,x);cout<<endl;
	}
	
	return 0;
}
