const int maxn=105;
int a[maxn][maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    f(n) f2(n){
        cin>>a[i][j];
        if(i>0) a[i][j]+=a[i-1][j];
        if(j>0) a[i][j]+=a[i][j-1];
        if(i>0&&j>0) a[i][j]-=a[i-1][j-1];
    }
    int ans=-1000000000;
    int k,l;
    f(n) f2(n) F(k,i,n,1) F(l,j,n,1){
        int cur=a[k][l];
        if(i>0) cur-=a[i-1][l];
        if(j>0) cur-=a[k][j-1];
        if(i>0&&j>0) cur+=a[i-1][j-1];
        ans=max(ans,cur);
    }
    cout<<ans<<endl;

    return 0;
}


