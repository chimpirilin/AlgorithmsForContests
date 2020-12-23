//This HLD implementation hasn't been tested, don't rely on it!
//And it uses ugly lazy segtree!
//Change it ASAP!

//Dado un arreglo y una operacion asociativa con neutro, get(i, j) opera sobre el rango [i, j).
typedef int Elem;//Elem de los elementos del arreglo
typedef int Alt;//Elem de la alteracion
const Elem neutro=0; const Alt neutro2=0;
#define operacion(x,y) x+y
#define MAXN 100000

struct RMQ{
	int sz_;
	Elem t[4*MAXN];
	Alt dirty[4*MAXN];//las alteraciones pueden ser de distinto Elem
	Elem &operator[](int p){return t[sz_+p];}
    
	void init(int n){//O(nlgn)
		sz_ = 1 << (32-__builtin_clz(n));
		for(int i=0; i<2*sz_;++i){
			t[i]=neutro;
			dirty[i]=neutro2;
		}
	}
	void updall(){//O(
		for(int i=sz_-1; i>=0;--i)
			t[i]=operacion(t[2*i], t[2*i+1]);
		}
	void opAltT(int n,int a,int b){//altera el valor del nodo n segun su dirty y el intervalo que le corresponde.
		t[n] += dirty[n]*(b-a);
	} //en este caso la alteracion seria sumarle a todos los elementos del intervalo [a,b) el valor dirty[n]
	void opAltD(int n ,Alt val){
		dirty[n] += val;
	}//actualiza el valor de Dirty "sumandole" val. podria cambiar el valor de dirty dependiendo de la operacion que se quiera al actualizar un rango. Ej:11402.cpp
	void push(int n, int a, int b){//propaga el dirty a sus hijos
		if(dirty[n]!=neutro2){
			opAltT(n,a,b); //t[n]+=dirty[n]*(b-a);//altera el nodo 
			if(n<sz_){
				opAltD(2*n,dirty[n]);//dirty[2*n]+=dirty[n];
				opAltD(2*n+1,dirty[n]);//dirty[2*n+1]+=dirty[n];
			}
			dirty[n]=neutro2;
		}
	}

	Elem get(int i, int j, int n, int a, int b){//O(lgn)
		if(j<=a || i>=b) return neutro;
		push(n, a, b);//corrige el valor antes de usarlo
		if(i<=a && b<=j) return t[n];
		int c=(a+b)/2;
		return operacion(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
	}
	Elem get(int i, int j){return get(i,j,1,0,sz_);}
	//altera los valores en [i, j) con una alteracion de val
	void alterar(Alt val, int i, int j, int n, int a, int b){//O(lgn)
		push(n, a, b); //si el push es muy caro, esta linea se podría pasar después de los ifs.
		if(j<=a || i>=b) return;
		if(i<=a && b<=j){
			opAltD(n,val);//actualiza el valor de Dirty por val.
			push(n,a,b);
			return;//este nodo esta totalmente contenido por el intervalo a alterar, no es necesario que se lo pases a los hijos.. por ahora..
		}
		int c=(a+b)/2;
		alterar(val, i, j, 2*n, a, c), alterar(val, i, j, 2*n+1, c, b);
		t[n]=operacion(t[2*n], t[2*n+1]);//por esto es el push de arriba
	}
	void alterar(Alt val, int i, int j){alterar(val,i,j,1,0,sz_);}

	}
};

RMQ segtree;

constexpr int tam=100009;
vi adl[tam];
int depth[tam],par[tam],subtree[tam],pos[tam],head[tam];
constexpr int VALUES_IN_EDGES=1;
map<ii,Elem> edgescost;

void dfsSubtree(int node=1){
    if(par[node]) adl[node].erase(find(all(adl[node]),par[node]));
    subtree[node]=1;
    fa(x,adl[node]){
        par[x]=node;
        depth[x]=depth[node]+1;
        dfsSubtree(x);
        subtree[node]+=subtree[x];
        if(subtree[x] > subtree[adl[node][0]]) swap(x,adl[node][0]);
    }
}

void decompose(int node=1, Elem cost=0){
    static int timer=0; //Set to 1 if DS is 1-indexed!
    pos[node]=timer++;
    segtree.alterar(cost,pos[node],pos[node]+1);
    fa(x,adl[node]){
        head[x]=(x==adl[node][0]?head[node]:x);
        int a=x;
        int b=node;
        if(a>b) swap(a,b);
        decompose(x,edgescost[{a,b}]);
    }
}

void modifypath(int u, int v, int val){
    for(;head[u]!=head[v];v=par[head[v]]){
        if(depth[head[u]]>depth[head[v]]) swap(u,v);
        segtree.alterar(val,pos[head[v]],pos[v]+1);
    }
    if(head[u]>depth[v]) swap(u,v);
    segtree.alterar(val,pos[u]+VALUES_IN_EDGES,pos[v]+1);
}

Elem querypath(int u, int v){
    Elem ans=0;
    for(;head[u]!=head[v];v=par[head[v]]){
        if(depth[head[u]]>depth[head[v]]) swap(u,v);
        ans+=segtree.get(pos[head[v]],pos[v]+1);
    }
    if(head[u]>depth[v]) swap(u,v);
    ans+=segtree.get(pos[u]+VALUES_IN_EDGES,pos[v]+1);
    return ans;
}

void modifysubtree(int v, int val){
    segtree.alterar(val,pos[v]+VALUES_IN_EDGES,pos[v]+subtree[v]);
}

int lca(int u, int v){
    for(;head[u]!=head[v];v=par[head[v]]){
        if(depth[head[u]]>depth[head[v]]) swap(u,v);
    }
    return depth[u]<depth[v]?u:v;
}

void init(){
    //1 is root, change it if necessary
    par[1]=depth[1]=0;
    head[1]=1;
    segtree.init(tam);
    segtree.updall();
    dfsSubtree();
    decompose();
}

//This library needs serious testing!
int main(){
//    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    int q;
    cin>>q;
    int a,b;
    Elem c;
    f(n){
        cin>>a>>b>>c;
        if(a>b) swap(a,b);
        adl[a].pb(b);
        adl[b].pb(a);
        edgescost[{a,b}]=c;
    }
    init();
    int u,v;
    while(q--){
        char x;
        cin>>x;
        if(x=='p'){
            cin>>u>>v>>c;
            modifypath(u,v,c);
        }else if(x=='s'){
            cin>>u>>c;
            modifysubtree(u,c);
        }else{
            cin>>u>>v;
            cout<<querypath(u,v)<<endl;
        }
    }
    return 0;
}
