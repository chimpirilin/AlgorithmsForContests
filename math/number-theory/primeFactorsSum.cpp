#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

/*long long sieve_size;
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

int primeFactorsSum(long long n) {
	sieve(n);
	long long index = 0, primeF = primes[index], ans = 0;
	long long lim = sqrt(n);
	while(primeF <= lim){
		while(n%primeF == 0){
			n /= primeF;
			ans+=primeF;
		}
		primeF = primes[++index];
	}

	if (n != 1)
		ans+=n;
	return ans;
}*/

//This one is slower but uses way less space
int primeFactorsSum(long long n) {
	long long ans = 0;
	long long lim = sqrt(n);
	while(n%2==0){
		n/=2;
		ans+=2;
	}
	for(long long i = 3; i <= lim; i+=2){
		while(n%i == 0){
			n /= i;
			ans+=i;
		}
	}

	if (n > 1)
		ans+=n;
	return ans;
}

int main(){
	cout << primeFactorsSum(20) << endl;
}
