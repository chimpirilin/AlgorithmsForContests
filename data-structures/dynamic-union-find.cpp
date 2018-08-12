#include <bits/stdc++.h>

using namespace std;

template<class T>
class UnionFind
{
public:
    unordered_map<T, T> parent;
    unordered_map<T, int> degree;
    unordered_map<T, int> setSize;
    int connectedComp=0;

    T getParent(T vertex){
        if(!exists(vertex))
            return -(1<<30);
        if(parent[vertex]==vertex)
            return vertex;
        getParent(parent[vertex]);
        parent[vertex]=getParent(parent[vertex]);
        return parent[vertex];
    }

    bool inSameSet(T x, T y){
        return (getParent(x)==getParent(y));
    }

    bool exists(T vertex){
        if(parent.find(vertex)==parent.end())
            return false;
        return true;
    }

    int sizeOfSet(T x){
        if(!exists(x))
            return -1;
        return setSize[getParent(x)];
    }

    void unionSet(T a, T b){
        T x=getParent(a);
        T y=getParent(b);
        if(x==y) return;
        if(degree[x]>degree[y]){
            parent[y]=x;
            degree[x]=degree[y]+degree[x];
            setSize[x] += setSize[y];
        }else{
            parent[x]=y;
            degree[y]=degree[y]+degree[x];
            setSize[y] += setSize[x];
        }
        --connectedComp;
    }
    void insertSet(T x){
        if(exists(x))
            return;
        parent.insert({x,x});
        degree.insert({x,1});
        setSize.insert({x,1});
        ++connectedComp;
    }
};

int main(){
    UnionFind<int> u;
    u.insertSet(1);
    u.insertSet(3);
    u.insertSet(2);
    u.insertSet(13);
    u.insertSet(4);
    u.insertSet(12);
    u.unionSet(1, 2);
    u.unionSet(4, 3);
    u.unionSet(1, 3);
    u.unionSet(12, 13);
    cout<<u.setSize[13]<<endl;
    cout<<u.connectedComp<<endl;
    return 0;
}
