#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

const int max=10000001;
bool v[max];
int len, sp[max];

//sp stores the smallest prime that divides n
void factsieve(){
	for (int i = 2; i < max; i += 2)
		sp[i] = 2;
	for (ll i = 3; i < max; i += 2){
		if (!v[i]){
			sp[i] = i;
			for (ll j = i; (j*i) < max; j += 2){
				if (!v[j*i])
					v[j*i] = true, sp[j*i] = i;
			}
		}
	}
}


//o(log n)
//first run factsieve
vector<int> fact(ll n){
	vector<int> ans;
	while(n>1){
		ans.push_back(sp[n]);
		n/=sp[n];
	}
	return ans;
}

int main(){
	//~ int x;
	//~ cin>>x;
	//~ auto pr = primeFactors(x);
	//~ for (int i = 0; i < (int)pr.size(); ++i){
		//~ cout << pr[i] << endl;
	//~ }
	factsieve();
	int x;
	cin>>x;
	for(auto item:fact(x)){
		cout<<item<<" ";
	}
	cout<<endl;
	return 0;
}
