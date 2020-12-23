class UnionFind
{
public:
    vector<int> p, rank,setSize;
    int numSets;
    UnionFind(int N){
        numSets=N; //How many sets there are
        p.assign(N,0);
        rank.assign(N,0);
        //setSize[findSet(i)] contains the size of the set containing i
        //Might not be needed in most cases
        setSize.assign(N, 1);
        for(int i = 0; i < N; ++i){
            p[i]=i;
        }
    }
    int findSet(int i){
         return (p[i]==i) ? i : (p[i]=findSet(p[i]));
    }
    void unionSet(int i, int j){
		//To check if they are in the same set
        if(findSet(i)==findSet(j)) return;
        --numSets;
        int x=findSet(i);
        int y=findSet(j);
        if(rank[x]>rank[y]){
            p[y]=x;
            setSize[x] += setSize[y];
        } else{
            p[x]=y;
            setSize[y] += setSize[x];
            if(rank[x]==rank[y]) ++rank[y];
        }
    }
    int sizeOfSet(int i){
        return setSize[findSet(i)];
    }
};

int main(){
    UnionFind u(20);
    return 0;
}
