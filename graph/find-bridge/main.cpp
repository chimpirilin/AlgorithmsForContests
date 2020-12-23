vector<pii> bridges;
vii adl[tam];
int low[tam];
int ord[tam];
int parent[tam];
bool visited[tam];
int cnt=0;

void add(int a,int b){
    adl[a].pb({b,1});
}

void findBridges(int w){
    ord[w]=++cnt;
    low[w]=ord[w];
    visited[w]=true;
    for(int i=0;i<adl[w].size();++i){
        int edge=adl[w][i].fff;
        if(!visited[edge]){
            parent[edge]=w;
            findBridges(edge);
            if(low[edge]<low[w]) low[w]=low[edge];
            if(low[edge]==ord[edge]) bridges.pb({w,edge});
        }else if(edge!=parent[w])
            if(ord[edge]<low[w])
                low[w]=ord[edge];
    }
}

int main(){
    int start=0;
    int t;cin>>t;while(t--){
        int a,b;cin>>a>>b;
        add(a,b);
    }
    memset(visited,false,sizeof visited);
    findBridges(start);
    if(!bridges.empty()){
        cout<<"Bridges: "<<endl; 
        for(auto x:bridges)
            cout<<x.fff<< "->"<<x.sss<<endl;
    }else cout<<"There are no briges!"<<endl;

    return 0;
}

