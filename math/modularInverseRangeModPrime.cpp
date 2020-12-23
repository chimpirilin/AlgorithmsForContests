int const tam=100005;
const int MOD=1000000007;
int inv[tam];


void prec(){
    inv[1]=1;
    int i;
    fi(i,2,tam){
        inv[i]=(MOD-(MOD/i)*inv[MOD%i]%MOD)%MOD;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}

