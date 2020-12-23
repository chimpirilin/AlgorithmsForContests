#define tipo int

//0-indexed!
struct RMQ{
	#define LVL 10
	tipo vec[LVL][1<<(LVL+1)];
	tipo &operator[](int p){return vec[0][p];}
	tipo get(int i, int j) {//intervalo [i,j)
		int p = 31-__builtin_clz(j-i);
		return min(vec[p][i],vec[p][j-(1<<p)]);
	}
	void build(int n) {//O(nlogn)
		int mp = 31-__builtin_clz(n);
		for(int p=0; p<mp;++p)
			for(int x=0; x<n-(1<<p);++x)
				vec[p+1][x] = min(vec[p][x], vec[p][x+(1<<p)]);
}};

int main(){
	RMQ sparse;
	int n;cin>>n;
	for(int i=0; i<n;++i){
		int x;
		cin>>x;
		sparse[i]=x;
	}
	sparse.build(n);
	cout<<sparse.get(5,6);cout<<endl;
	cout<<sparse.get(5,7);cout<<endl;
	cout<<sparse.get(5,8);cout<<endl;
	
	
}
