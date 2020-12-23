int constexpr tam=100005;
constexpr int mod=1000000007;
ll inv[tam];
ll fac[tam];
ll finv[tam];

void prec(){
    inv[1]=1;
    fac[0]=fac[1]=1;
    finv[1]=finv[0]=1;
    F(i,2,tam,1){
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        fac[i]=fac[i-1]*(ll)i%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
}

ll nck(int x,int y){
    if(y>x) return 0;
    return fac[x]*(finv[y]*finv[x-y]%mod)%mod;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}

