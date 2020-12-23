//we receive a range a[l:r] for each query, this time we have to find a subsegment a[l1:r1]
//such that l≤l1 and r1≤r and the sum of the elements of this segment is maximal.
//Can modify individual elements
//Allow negative values
//optimal subsegment can be empty (e.g. if all elements are negative).
constexpr int maxn=100001;
int n;
int tmp[100001];
int a[maxn];

struct data{
    int sum,pref,suf,ans;
    data(int val){
        sum=val;
        pref=suf=ans=max(val,0);
    }
    data(){
        data(0);
    }
};

struct SegmentTree{
    data tree[4*maxn];
    data combine(data l, data r){
        data res;
        res.sum=l.sum+r.sum;
        res.pref=max(l.pref,l.sum+r.pref);
        res.suf=max(r.suf,r.sum+l.suf);
        res.ans=max(max(l.ans,r.ans),l.suf+r.pref);
        return res;
    }

    void build(int node,int L, int R){
        if(L==R){
            tree[node]=data(tmp[L]);
            return;
        }
        int mid=(L+R)>>1;
        build(node*2,L,mid);
        build(node*2+1,mid+1,R);
        tree[node]=combine(tree[2*node],tree[node*2+1]);
    }

    void update(int node,int pos,int val,int L,int R){
        if(L==R){
            tree[node]=data(val);
            return;
        }
        int mid=(L+R)>>1;
        if(pos<=mid){
            update(node*2,pos,val,L,mid);
        }else{
            update(node*2+1,pos,val,mid+1,R);
        }
        tree[node]=combine(tree[node*2],tree[node*2+1]);
    }

    data query(int node,int ql,int qr,int l,int r){
        if(r<ql||l>qr) return data(0);
        if(l==ql&&r==qr) return tree[node];
        int mid=(l+r)>>1;
        return combine(query(node*2,ql,mid,l,mid),query(node*2+1,mid+1,qr,mid+1,r));
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc=1,t,s;
    cin>>t;
    int cnt[100001];
    int bad[100001];
    while(t--){
        cin>>n>>s;
        queue<int> pos0[100001];
        for(int i=1;i<=n;++i){
            cin>>a[i];
            cnt[a[i]]=0;
            tmp[i]=0;
            bad[a[i]]=-1;
        }
        for(int i=1;i<=n;++i){
            if(cnt[a[i]]==s){
                tmp[i]=-s;
                bad[a[i]]=i;
            }
            else if(cnt[a[i]]<s){
                tmp[i]=1;
                ++cnt[a[i]];
            }else{
                pos0[a[i]].push(i);
            }
        }
        SegmentTree st;
        
        int ans=st.query(1,1,n,1,n).ans;
        for(int i=2;i<=n;++i){
            if(bad[i]!=-1){
                st.update(1,bad[i],1,1,n);
                bad[i]=-1;
                if(pos0[a[i-1]].empty()==false){
                    bad[i]=pos0[a[i-1]].front();
                    pos0[a[i-1]].pop();
                }
            }
            ans=max(ans,st.query(1,i,n,1,n).ans);
        }
        cout<<"Case #"<<tc++<<": "<<ans<<endl;

    }
    

    return 0;
}
