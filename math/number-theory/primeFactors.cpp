#include <bits/stdc++.h>

using namespace std;

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

vector<int> primeFactors(long long n) {
	long long lim = sqrt(n);
	sieve(n);
	vector<int> factors;
	long long index = 0, primeF = primes[index];
	while(primeF <= lim){
		while(n%primeF == 0){
			n /= primeF;
			factors.push_back(primeF);
		}
		primeF = primes[++index];
	}

	if (n != 1)
		factors.push_back(n);
	return factors;
}

unordered_map<long long, int> primeFactors2(long long n){
	long long lim = sqrt(n);
	unordered_map<long long, int> factors;
	long long index = 0, primeF = primes[index];
	while(primeF <= lim){
		while(n%primeF == 0){
			n /= primeF;
			if(factors.find(primeF)!=factors.end())
				++factors[primeF];
			else
				factors[primeF]=1;
        }
		primeF = primes[++index];
	}
	if (n != 1)
		factors[n]=1;
	return factors;
}

int main(){

	auto pr = primeFactors(8);
	for (int i = 0; i < pr.size(); ++i)
	{
		cout << pr[i] << endl;
	}
	return 0;
}
