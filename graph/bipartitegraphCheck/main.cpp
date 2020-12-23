const int tam=1000009;
vii adl[tam];
int color[tam];

//bipartite graph check-odd cycle check

bool dfs(int v, int c){
    if(c==2) color[v]=1;
    else color[v]=2;
    for(int i=0;i<adl[v].size();++i){
        if(color[adl[v][i].ff]==-1)
            return dfs(adl[v][i].ff,color[v]);
        else if(color[adl[v][i].ff]==color[v]) 
            return false;
    }
    return true;
}
