#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define lob lower_bound
#define upb upper_bound
#define ff first
#define ss second
#define beg begin
#define clear(a,b) memset(a,b,sizeof a)
#define sz size
#define tam 1000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=(1<<30);

vi d(tam,inf);
vii adl[tam];

void bfs(int source){
	queue<int> q;q.push(source);
	d[source]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		//~ cout<<"Layer: "<< d[u]+1;
		//~ cout<<endl;
		for(int i=0; i<(int)adl[u].sz();++i){
			ii v=adl[u][i];
			if(d[v.ff]==inf){
				d[v.ff]=d[u]+1;
				//~ cout<<v.ff<< " ";
				q.push(v.ff);
			}
		}
		//~ cout<<endl;
	}
}

void add(int a,int b){
    adl[a].pb({b,1});
    adl[b].pb({a,1});
}


int main(){
	ios::sync_with_stdio(false);
	int start=5;
    int n;cin>>n;while(n--){
        int a, b;cin>>a>>b;add(a,b);
        //~ start=a;
    }
    bfs(start);
	
	
	return 0;
}
