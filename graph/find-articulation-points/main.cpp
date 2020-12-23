vii adl[tam];
int ord[tam];
int low[tam];
int parent[tam];
bool visited[tam];
int cnt=-1;
int dfsRoot;
int rootChildren;
vector<int> articulationPoints;

void add(int a,int b){
    adl[a].pb({b,1});
}

void artPoints(int w){
    ord[w]=++cnt;
    low[w]=ord[w];
    visited[w]=true;
    for(int i=0;i<adl[w].size();++i){
        int edge=adl[w][i].fff;
        if(!visited[edge]){
            parent[edge]=w;
            if(w==dfsRoot) ++rootChildren;
            artPoints(edge);
            if(low[edge]<low[w]) low[w]=low[edge];
            if(low[edge]>=ord[w]){
                if(w==dfsRoot){
                    if(rootChildren>=2)
                        articulationPoints.pb(w);
                }else
                    articulationPoints.pb(w);
            }
        }else if(edge!=parent[w]){
            if(ord[edge]<low[w])
                low[w]=ord[edge];
        }
    } 
}

int main(){
    int t;cin>>t;while(t--){
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    memset(visited,false,sizeof visited);
    dfsRoot=0;
    artPoints(dfsRoot);
    if(!articulationPoints.empty()){
        cout<<"Articulation  points:"<<endl;
        for(auto x:articulationPoints)
            cout<<x <<" ";
    }else
        cout<<"There aren't articulation points!";
    cout<<endl;
    return 0;
}
