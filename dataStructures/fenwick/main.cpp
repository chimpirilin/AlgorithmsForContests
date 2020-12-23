#define tipo int
#define MAXN 17

struct Fenwick{
	int tam; //los elementos van de 1 a tam
	tipo t[MAXN];
	void init (int n){
		tam = n;
		memset(t,0,sizeof t);
	}
	void adjust(int p, tipo v){
		for(int i=p; i<tam; i+=(i&-i)) 
			t[i]+=v;
	}
	tipo sum(int p){
		tipo s=0;
		for(int i=p; i; i-=(i&-i)) s+=t[i];
		return s;
	}
	//get largest value with cumulative sum less than or equal to x;
	//for smallest, pass x-1 and add 1 to result
	//MAXN should be a power of 2+1! 
	int getind(tipo x) {//O(lgn) -- VER!
	  	int idx = 0, mask = MAXN-1;
	  	while(mask && idx < MAXN-1) {
	   		int tmp = idx + mask;
			if(x >= t[tmp])
		  		idx = tmp, x -= t[tmp];
	   		mask >>= 1;
	  	}
	  	return idx;
	}
};

int main(){
	Fenwick tree;
	tree.init(MAXN);
	int xxx;
	cin>>xxx;
	for(int i=1; i<=xxx;++i){
		int x;
		cin>>x;
		tree.adjust(i,x);
	}
	for(int i=1; i<MAXN;++i){
		cout<<tree.sum(i)<< " ";
	}
	
	return 0;
}
