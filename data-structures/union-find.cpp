#include <bits/stdc++.h>

using namespace std;

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

int main(){
    UnionFind u(20);
    u.unionSet(0,1);
    u.unionSet(0,3);
    u.unionSet(4,5);
    u.unionSet(5,7);
    u.unionSet(8,6);
    u.unionSet(0,8);
    u.unionSet(10,9);

    cout<<u.sizeOfSet(4);


    return 0;
}