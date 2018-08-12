#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long sieve_size;
vector<int> primes;
bitset<10000009> bs;

void sieve(long long upperbound){
    sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs [1] = 0;
    for(long long i = 2; i <= sieve_size; i++)
    	if(bs[i]){
	    	for (long long j = i*i; j <= sieve_size; j+=i)
	    		bs[j] = 0;
	    	primes.push_back((int)i);
	    }
}

int eulerPhi(long long n){
	long long ans = n;
	if(n%2==0){
        while(n%2==0)
            n/=2;
		ans -= (ans/2);
	}
	for(long long i = 3; i*i <= n; i+=2){
		if(n%i==0)
			ans -= (ans/i);
		while(n%i == 0){
			n /= i;
		}
	}

	if (n > 1)
		ans-=(ans/n);
	return ans;
}

int main(){
	cout << eulerPhi(9);
}
