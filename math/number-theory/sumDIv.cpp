#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

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

int divisorSum(long long n) {
	long long index = 0, primeF = primes[index];
	long long ans=1;
	long long lim = sqrt(n);
	while(primeF <= lim){
		long long power=0;
		while(n%primeF == 0){
			n /= primeF;
			++power;
		}

		ans*=((long long)pow((double)primeF, power+1.0)-1)/(primeF-1);

		primeF = primes[++index];
	}

	if (n != 1)
		ans*=((long long)pow((double)n, 2.0)-1)/(n-1);
	return ans;
}

int main(){
	sieve(1000);
	cout <<divisorSum(20);
}
