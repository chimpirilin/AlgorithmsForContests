using namespace std;
#include <bits/stdc++.h>
long long sieve_size;
vector<int> primes;
bitset<10000001> bs;

void sieve(long long upperbound){
    sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs [1] = 0;
    for(long long i = 2; i <= sieve_size; i++)
    	if(bs[i]) {
	    	for (long long j = i*i; j <= sieve_size; j+=i)
	    		bs[j] = 0;
	    	primes.push_back((int)i);
	    }	    
}

int differentPrimeFactors(long long n) {
	long long index = 0, primeF = primes[index], ans = 0;

	long long lim = sqrt(n);
	while(primeF <= lim){
		if(n%primeF == 0)
			ans++;
		while(n%primeF == 0){
			n /= primeF;
		}
		primeF = primes[++index];
	}

	if (n != 1)
		ans++;
	return ans;
}

int main(int argc, char const *argv[]){
	sieve(1000);
	int n;
	while(cin>>n&&n){
		cout << n << " : " << differentPrimeFactors(n)<<endl;
	}
	return 0;
}