#include <bits/stdc++.h>
 
using namespace std;
 
#define tipo long long
constexpr int maxn=2e5+5;  // limit for array size
int n;  // array size
tipo t[2 * maxn];
 
void build(){  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}
 
void modify(int p, tipo value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}
 
tipo query(int l, int r) {  // sum on interval [l, r)
  tipo res = 0.0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}
 
int main(){
    ios::sync_with_stdio(0);
    int q;
    cin>>n>>q;
    for(int i=0;i<n;++i){
        cin>>t[n+i];
    }
    build();
    int a,b,c;
    while(q--){
        cin>>a>>b>>c;
        if(a==1){
            modify(b-1,c);
        }else{
            cout<<query(b-1,c)<<endl;
        }
    }
    return 0;
}
