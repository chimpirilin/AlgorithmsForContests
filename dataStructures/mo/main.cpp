const int inf=(int)1e9;
const int tam=30005;
int n,q;
int a[tam];
const int block_size=173;
int answer=0;
int freq[1000005];

//Example of Mo's algorithm. You should modify add and remove for other problems.
//SPOJ DQUERY

struct query {
    int l, r, idx;
    bool operator<(query other){
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
    query(int ll, int rr, int i):l(ll),r(rr),idx(i){}
};

vector<query> queries;


void add(int idx){
    auto &ref=freq[a[idx]];
    ++ref;
    if(ref==1) ++answer;
}

void remove(int idx){
    auto &ref=freq[a[idx]];
    --ref;
    if(ref==0) --answer;
}
vi pre(){
    sort(all(queries));
    vi ans(SZ(queries));
    answer=0;
    int l=0;
    int r=-1;
    for(auto x : queries){
        while(l>x.l){
            --l;
            add(l);
        }
        while(r>x.r){
            remove(r);
            --r;
        }
        while(l<x.l){
            remove(l);
            ++l;
        }
        while(r<x.r){
            ++r;
            add(r);
        }
        ans[x.idx]=answer;
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    cin>>q;
    int l,r;
    int cnt=-1;
    while(q--){
        ++cnt;
        cin>>l>>r;
        --l;--r;
        queries.pb(query(l,r,cnt));
    }
    auto v=pre();
    for(int i=0;i<SZ(v);++i){
        cout<<v[i]<<endl;
    }
    return 0;
}
