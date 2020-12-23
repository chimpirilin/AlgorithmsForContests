const int tam=500;
const int inf=(int)1e9;

int adm[tam+10][tam+10];
int V=tam,E;

void floydwarshall(){
	for(int k=0; k<V;++k)
		for(int i=0; i<V;++i)
			for(int j=0; j<V;++j)
				adm[i][j]=min(adm[i][j],adm[i][k]+adm[k][j]);
}
//Vertices from 0 to V-1
void init(){
	for(int i=0; i<V;++i){
		for(int j=0; j<V;++j){
			if(i==j) adm[i][j]=0;
			else adm[i][j]=inf;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin>>V>>E;
	init();
	for(int i=0; i<E;++i){
		int a,b,c;
		cin>>a>>b>>c;
        adm[a][b]=min(adm[a][b],c);
        adm[b][a]=min(adm[a][b],c); //iff the graph is undirected.
	}
	return 0;
}
