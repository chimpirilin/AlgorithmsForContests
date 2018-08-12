#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define lob lower_bound
#define upb upper_bound
#define ff first
#define ss second
#define beg begin()
#define en end()
#define sz size()
#define mem(a,b) memset(a,b,sizeof a)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

class UnionFind
{
public:
    vector<int> p, rank,setSize;
    int numSets;
    UnionFind(int N){
        numSets=N;
        p.assign(N,0);
        rank.assign(N,0);
        setSize.assign(N, 1);
        for(int i = 0; i < N; ++i){
            p[i]=i;
        }
    }

    int findSet(int i){
         return (p[i]==i) ? i : (p[i]=findSet(p[i]));
    }

    bool inSameSet(int i, int j){
        return (findSet(i)==findSet(j));
    }

    void unionSet(int i, int j){
        if(inSameSet(i,j))
            return;
        --numSets;
        int x=findSet(i);
        int y=findSet(j);
        if(rank[x]>rank[y]){
            p[y]=x;
            setSize[x] += setSize[y];
        }
        else{
            p[x]=y;
            setSize[y] += setSize[x];
            if(rank[x]==rank[y])
                ++rank[y];
        }
    }

    int sizeOfSet(int i){
        return setSize[findSet(i)];
    }

};

int E,V;
vector<pair<int, ii> > edgelist;

int mst(){
	int mstCost=0;
	UnionFind UF(V+1); //V+1 if it is from 0 to N otherwise UF(V)
	//~ assert(E==(int)edgelist.sz);
	
	for(int i=0; i<E;++i){
		auto front=edgelist[i];
		if(!UF.inSameSet(front.ss.ff,front.ss.ss)){
			mstCost+=front.ff;
			UF.unionSet(front.ss.ff,front.ss.ss);
		}
	}
	
	return mstCost;
}

int main(){
	ios::sync_with_stdio(false);
	cin>>V;
	cin>>E;
	int u,v,w;
	for(int i=0; i<E;++i){
		cin>>u>>v>>w;
		edgelist.pb({w,{u,v}});
	}
	
	sort(edgelist.beg,edgelist.en);
	
	cout<<mst();cout<<endl;
	
	
	return 0;
}
