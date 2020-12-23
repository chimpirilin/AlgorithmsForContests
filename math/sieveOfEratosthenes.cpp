#include <bits/stdc++.h>

using namespace std;

long long sieve_size;
bitset<100000009> bs;
int spf[10000010];

void sieve(long long upperbound, vector<long long> &primes){
    sieve_size = upperbound;
    bs.set();
    bs[0] = bs [1] = 0;
    for(long long i = 2; i <= sieve_size; i++)
    	if(bs[i]) {
			sp[i]=i;
	    	for (long long j = i*i; j <= sieve_size; j+=i)
	    		bs[j] = 0;
	    	primes.push_back(i);
	    }
}

//Do we really need segmented sieve Sir? Might get rid of it...
//Computes the primes in the range [l, u), note that l >=2
vector<long long> segmentedSieve(long long lower, long long n){
    long long limit = floor(sqrt(n))+1;
    vector<long long> primes; //We store the primes less than sqrt(n)
    sieve(limit, primes);

    long long low  = lower;
    long long high = lower+limit;
    if(n-lower<limit){
    	high = n;
	}

 	std::vector<long long> p;//We store the primes between [lower, n]
    while (low < n){
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
        for (long long i = 0; i < primes.size(); i++){
            long long loLim = floor(low/primes[i]) * primes[i];
            if (loLim < low)
                loLim += primes[i];
            for (long long j=loLim; j<high; j+=primes[i])
                mark[j-low] = false;
        }

        // Numbers which are not marked as false are prime
        for (long long i = low; i<high; i++){
        	long long index = i - low;
            if (mark[index] == true){
                p.push_back(i);
            }
        }

        // Update low and high for next segment
        low  = low + limit;
        high = high + limit;
        if (high >= n) high = n;
    }
    //Maximun range for segmented sieve is [sqrt(n)+1, n] if lower is a smaller value
    //than sqrt(n)+1 we need insert the primes less than sqrt(n)+1 until we reach lower
    auto it = primes.end();
    --it;
    //What a dirty code! But it's 6:30 AM and i haven't slept!
    while(*it>=lower){
    	p.insert(p.begin(), (*it));
    	--it;
    	if(it==primes.begin() && *it>=lower){
    		p.insert(p.begin(), (*it));
    		break;
    	}
    }

    return p;
}

bool isPrime(long long n, vector<ll> &primes) {
	if(n <= sieve_size) return bs[n];
	auto upp = (long long)sqrt(n);
	for (int i = 0;primes[i] <= upp and i <(int)primes.size(); ++i)
		if(n % primes[i] == 0) return false;
	return true;
}

int main(){
	//auto num = 1312312;
	//cout << (isPrime(num) ? "Is prime" : "Is not prime") << endl;

	//auto  v = segmentedSieve(2, 10000000);
    std::vector<long long> v;
    sieve(1000000, v);
	for(auto x:v)
		cout << x <<" ";

}
