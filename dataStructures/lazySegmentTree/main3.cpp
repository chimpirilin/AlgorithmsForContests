//0-indexed!
//[l,r]!
template<class T, int SZ> struct LazySeg { 
	static_assert(__builtin_popcount(SZ) == 1); // SZ must be power of 2
	const T ID = 0; T comb(T a, T b) { return a+b; }
	T seg[2*SZ], lazy[2*SZ]; 
	LazySeg() { f(2*SZ) seg[i] = lazy[i] = ID; }
	void push(int ind, int L, int R) { /// modify values for current node
		seg[ind] += (R-L+1)*lazy[ind]; // dependent on operation
		if (L != R) f(2) lazy[2*ind+i] += lazy[ind]; /// prop to children
		lazy[ind] = 0; 
	} // recalc values for current node
	void pull(int ind) { seg[ind] = comb(seg[2*ind],seg[2*ind+1]); }
	void build() {FF(i,SZ-1,1,1) pull(i); }
	void upd(int lo,int hi,T inc,int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind,L,R); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	T query(int lo, int hi, int ind=1, int L=0, int R=SZ-1) {
		push(ind,L,R); if (lo > R || L > hi) return ID;
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2; 
		return comb(query(lo,hi,2*ind,L,M),query(lo,hi,2*ind+1,M+1,R));
	}
};

int main(){
    constexpr maxn=1<<18;
    LazySeg<int,maxn> tree;
    int n;
    cin>>n;
    f(n) cin>>tree.seg[i+maxn];
    tree.build();
    int q;
    cin>>q;
    while(q--){
        int type,l,r;
        cin>>type>>l>>r;
        if(type==1){
            int val;
            cin>>val;
            tree.upd(l-1,r-1,val);
        }else{
            cout<<tree.query(l-1,r-1)<<endl;
        }        
    }
    return 0;
}
