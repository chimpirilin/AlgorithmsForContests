const int maxn=100010;
string t,p; //t=text, p=pattern
int b[maxn],n,m; //n=length of t, m=length of p
vi matches; //position of matches

void kmpPre(){
    int i=0,j=-1;
    b[0]=-1;
    while(i<m){
        while(j>=0 && p[i]!=p[j]) j=b[j];
        ++i,++j;
        b[i]=j;
    }
}

void kmp(){
    int i=0,j=0;
    while(i<n){
        while(j>=0 && t[i]!=p[j]) j=b[j];
        ++i,++j;
        if(j==m){
            matches.pb(i-j);
            j=b[j];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t>>p;
    n=sz(t);
    m=sz(p);
    kmpPre();
    kmp();
    debug()<<imie(matches);

    return 0;
}

