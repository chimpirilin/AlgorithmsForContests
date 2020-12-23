#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define ff first
#define ss second
#define sz(x) (int)(x).size()
#define f(n) for(int i=0;i<n;++i)
#define f2(n) for(int j=0;j<n;++j)
#define f3(n) for(int k=0;k<n;++k)
#define F(i,x,n,y) for(int i=x;i<n;i+=y)
#define FF(i,x,n,y) for(int i=x;i>=n;i-=y)
#define fa(x,y) for(auto x:y)

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<pair<ii,int>> viii;

//Warsaw debug template
#define LOCAL
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1,debug&>::type operator<<(c i){
sim > struct rge {c b,e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
#ifdef LOCAL
~debug() {cerr<<endl; }
eni(!=) cerr<< boolalpha << i; ris;}
eni(==) ris <<range(begin(i),end(i)); }
sim, class b dor(pair<b,c> d){
ris<<"("<<d.first<<","<<d.second<<")";
}
sim dor(rge<c> d){
    *this << "[";
    for(auto it=d.b;it!=d.e;++it)
        *this <<"," +(it==d.b)<< *it;
    ris<<"]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "["<<#__VA_ARGS__":"<<(__VA_ARGS__)<<"]"
//End of debug template

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    return 0;
}
