#include <bits/stdc++.h>

using namespace std;
vector<long long> euler;
int dp[2000001];

void eulerPhiRange(int lim){
	euler.reserve(lim+1);
	for (int i = 2; i <= lim; i++)
		euler[i] = i;
	for (int i = 2; i <= lim; i++)
		if (euler[i] == i)
			for (int j = i; j <= lim; j += i)
				euler[j] = (euler[j]/i)*(i-1);
}

void depth(int x){
	if(dp[x]!=0)
		return dp[x];
	int c=1;
	auto e=euler[x];
	while(e!=1){
		if(dp[e]!=0){
			c+=dp[x]+1;
			break;
		}
		e=euler[e];
		++c;
	}
	dp[x]=c;
}

int main(){
 	eulerPhiRange(2000001);
	int t;
	cin>>t;
	while(t--){
		int m, n;
		long long ans=0;
		cin>>m>>n;
		for(int i=m;i<=n;++i){
			ans+=depth(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}