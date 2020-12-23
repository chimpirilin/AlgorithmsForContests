#define tipo int
#define MAXN 17

struct Fenwick{
	int tam; //los elementos van de 1 a tam-1
	tipo t[MAXN][MAXN];
	void init (int n){
		tam = n;
		for(int i=0; i<MAXN;++i){
			memset(t[i],0,sizeof t[i]);
		}
	}
	void adjust(int p, int q, tipo v){
		for(int i=p; i<tam; i+=(i&-i)) 
			for(int j=q; j<tam; j+=(j&-j)) 
				t[i][j]+=v;
	}
	tipo sum(int p,int q){
		tipo s=0;
		for(int i=p; i; i-=(i&-i))
			for(int j=q; j; j-=(j&-j))
				s+=t[i][j];
		return s;
	}
	
	tipo sum(int a1, int b1, int a2, int b2){return sum(a2,b2)-sum(a1-1,b2) - sum(a2,b1-1) + sum(a1-1,b1-1);}
};

int main(){
	Fenwick tree;
	tree.init(MAXN);
	int n,m;
	cin>>n>>m;
	for(int i=n; i>=1;--i){
		for(int j=1; j<=m;++j){
			int x;
			cin>>x;
			tree.adjust(i,j,x);
		}
	}	
	cout<<endl;
	cout<<tree.sum(1,1,5,5);
	cout<<endl;
	cout<<tree.sum(1,1,3,3);
	cout<<endl;
	cout<<tree.sum(2,2,4,4);
	cout<<endl;
	
	
	return 0;
}
