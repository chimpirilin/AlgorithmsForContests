#include <bits/stdc++.h>

using namespace std;

//Computes the exponent of a prime p in n! (n factorial)
int getPower(long long n, long long p){
	int ans=0;
	for(long long power=p;power<=n;power*=p)
		ans+=n/power;
	return ans;
}


int main(int argc, char const *argv[])
{
	cout << getPower(100, 2)<<std::endl;;
	return 0;
}