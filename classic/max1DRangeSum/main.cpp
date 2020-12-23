int main(){
    int n;
    cin>>n;
    vi v;
    while(n--){
        int x;
        cin>>x;
        v.pb(x);
    }

    int sm=0;
    int ans=-1000000003;

    f(n){
        sm+=v[i];
        ans=max(ans,sm);
        if(sm<0)
            sm=0;
    }

    cout<<ans<<endl;

    return 0;
}
