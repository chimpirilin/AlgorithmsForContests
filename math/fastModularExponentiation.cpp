#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define SZ(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define endl '\n'
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=(int)1e9;
const int maxint=0x7f;

const ll mod=1000000007; //10^9+7.

//Compute (a*b)%mod, it avoids overflow.
//It makes the program slow so try to avoid it.
ll multmod(ll a, ll b){
    ll x = 0,y=a%mod;
    while(b > 0){
        if(b&1) x = (x+y)%mod;
        y = (y*2)%mod;
        b>>=1;
    }
    return x%mod;
}

ll expmod(ll a, ll b){
	ll r = 1LL;
	ll x = a%mod;
	while(b > 0){
		if(b&1) r=(r*x)%mod; //multmod(r, x, c);
		b>>=1LL;
        x=(x*x)%mod;
	}
	return r;
}

int main(){
	cout << expmod(13, 20);
	return 0;
}
