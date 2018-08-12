#include <bits/stdc++.h>

using namespace std;
//Just set i=2 if you don't want to include 1 and n
vector<int> divisors(long long n) {
	long long lim = sqrt(n);
	vector<int> v;
	for(long long i = 1; i <= lim; ++i){
		if(n%i==0){
			v.push_back(i);
			if(i!=n/i) //To avoid adding a number twice in case that n is a perfect square
				v.push_back(n/i);
		}
	}
	return v;
}

int main(int argc, char const *argv[])
{
	int n = 12;
	auto v = divisors(n);
	for(auto x:v) cout << x << " ";
	return 0;
}
