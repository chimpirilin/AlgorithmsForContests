#include <bits/stdc++.h>

using namespace std;

long long sieve_size;
bitset<10000009> bs;

void sieve(long long upperbound, vector<long long> &primes){
    sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs [1] = 0;
    for(long long i = 2; i <= sieve_size; i++)
    	if(bs[i]) {
	    	for (long long j = i*i; j <= sieve_size; j+=i)
	    		bs[j] = 0;
	    	primes.push_back(i);
	    }
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, c;
	while(cin >> n >> c){
		sieve(n);
		primes.insert(1, 0);
		int s = 2*c;
		if((primes.size())%2!=0)
			--s;
		int start = 0;
		if(s<=primes.size())
			start = primes.size()-s;
		for(int i = start, j=1;j<=s;++i, ++j)
			cout << primes[i];
	}
	return 0;
}