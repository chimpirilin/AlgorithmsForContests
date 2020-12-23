constexpr int maxn=100;

struct matrix{
    int m,n;
    int mat[maxn][maxn];
    matrix(int nn=0,int mm=0){
        n=nn;
        m=mm;
        f(n) f2(m) mat[i][j]=0;
    }
};

matrix matmul(matrix &a,matrix &b){
    assert(a.m==b.n);
    matrix c(a.n,b.m);
    f(c.n) f2(c.m) f3(a.m) c.mat[i][k]+=a.mat[i][j]*b.mat[j][k];
    return c;
}

matrix matpow(matrix &a, int b){
    assert(a.n==a.m&&b>=0);
    matrix res(a.n,a.n);
    f(res.n) res.mat[i][i]=1; //identity matrix
    while(b>0){
       if(b&1) res=matmul(res,a);
       b>>=1;
       a=matmul(a,a);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    matrix a(2,2);
    a.mat[0][0]=1;
    a.mat[0][1]=1;
    a.mat[1][0]=1;
    a.mat[1][1]=0;
    auto c=matpow(a,5);
    f(2){
        f2(2) cout<<c.mat[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

