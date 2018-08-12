#include <iostream>
#include <algorithm>

using namespace std;

long long x, y, d;

//We use this function to avoid overflow.
long long multmod(long long a, long long b, long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

//Sometimes modInv returns negative residues
void negToPos(long long &x, long long mod){
	while(x<0)
		x+=mod;
}

long long exp(long long a, long long b, long long c){
	long long res = 1;
	long long x = a%c;

	while(b > 0){
		if(b%2==1)
			res = multmod(res, x, c);
		x=multmod(x, x, c);
		b/=2;
	}
	return res;
}

//Computes the modular multiplicative inverse of a modulo p and p is prime
//ax=1(modp)
bool modInvP(long long a, long long p, long long &ans){
	if(__gcd(a, p) != 1)
		return false;
	ans = exp(a, p-2, p);
	if(ans < 0)
		negToPos(ans, p);
	return true;
}

int main(){
	long long ans;
	modInvP(1000, 10000007, ans);
	cout <<  ans << std::endl;
	return 0;
}
