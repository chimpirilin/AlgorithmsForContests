const int maxn=100001;

int a[maxn];
int d[maxn+1];

int main(){
	int n;cin>>n;
	for(int i=1; i<=n;++i){
		cin>>a[i];
		d[i]=a[i]-a[i-1];
	}
	
	int q;cin>>q;
	int l,r,x;
	while(q--){
		cin>>l>>r>>x;
		d[l]+=x;
		d[r+1]-=x;
	}

	for(int i=1; i<=n;++i){
		a[i]=d[i]+a[i-1];
	}
	
	for(int i=1; i<=n;++i){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
