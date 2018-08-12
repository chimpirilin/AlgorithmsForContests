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
const int tam=1000;

vi tp;
vi adl[tam+10];
bool visited[tam+10];


void topo(int node){
	visited[node]=true;
	for(int i=0; i<(int)adl[node].sz;++i){
		int v=adl[node][i];
		if(!visited[v]); topo(v);
	}
	
	ts.pb(node);
}

int main(){
	ios::sync_with_stdio(false);
	mem(visited,false);
	int V=100;
	for(int i=0; i<V;++i){
		if(!visited[i]){
			topo(i);
		}
	}
	
	//ts have a toposort in reverse order
	
	
	return 0;
}

