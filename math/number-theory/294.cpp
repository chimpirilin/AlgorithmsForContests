#include <bits/stdc++.h>

using namespace std;

int numberOfDivisors(long long n) {
	long long lim = sqrt(n);
	long long ans = 1,aux = 0;
	while(n%2==0){
		n/=2;
		++aux;
	}
	ans*=(aux+1);
	for(long long i = 3; i <= lim; i+=2){
		long long power = 0;
		while(n%i == 0){
			n /= i;
			power++;
		}
		ans *= (power+1);
	}

	if (n > 1)
		ans*=2;
	return ans;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--){
		int ma=0, l, u, cur;

		cin>>l>>u;
		for(int i=l;i<=u;++i){
			auto ans = numberOfDivisors(i);
			if(ans > ma){
				cur = i;
				ma = ans;
			}
		}

		cout << "Between " << l << " and " << u << ", " << cur << " " <<" has a maximum of "<< ma<< " divisors."<<endl;
	}
	return 0;
}