const int tam=500;
const int inf=(int)1e9;

int adm[tam+10][tam+10];
int V,E;

void warshall(){
	for(int k=0; k<V;++k)
		for(int i=0; i<V;++i)
			for(int j=0; j<V;++j)
				adm[i][j] |= adm[i][k] & adm[k][j]);
}

int main(){
	ios::sync_with_stdio(false);
	cin>>V>>E;
	mem(adm,o);
	for(int i=0; i<E;++i){
		int a,b;
		cin>>a>>b;
		adm[a][b]=1;
	}
	warshall();
	return 0;
}
