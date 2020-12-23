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

int numberOfDivisors(long long n) {
	long long lim = sqrt(n);
	sieve(n);
	long long index = 0, primeF = primes[index], ans = 1;
	while(primeF <= lim){
		long long power = 0;
		while(n%primeF == 0){
			n /= primeF;
			power++;
		}
        ++index;
		ans *= (power+1);
        if(n==1||index>=sz(primes)) break;
		primeF = primes[index];
	}

	if (n != 1)
		ans*=2;
	return ans;
}*/

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


int main(){
	cout << numberOfDivisors(999999924);
	return 0;
}
