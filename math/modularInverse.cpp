#include <iostream>

using namespace std;

long long x, y, d;
//Extended euclid returns a triple that satisfies the equation
//ax+by=d where d is gcd(a, b)
void extendedEuclid(long long a, long long b){
	if(b == 0){
		x = 1;
		y = 0;
		d = a;
		return;
	}
	extendedEuclid(b, a%b);
	int x1 = y;
	int y1 = x-(a/b)*y;
	x = x1;
	y = y1;

}

//Sometimes modInv returns negative residues

void negToPos(long long &x, long long mod){
    x=(mod+(x%mod))%mod;
}

//Computes the modular multiplicative inverse of a modulo m
//ax=1(modm)
bool modInv(long long a, long long m, long long &ans){
	extendedEuclid(a, m);
	if(d != 1) 
		return false;
	ans = x;
	if(x < 0)
		negToPos(ans, m);
	return true;
}

int main(){
	long long ans;
	modInv(9, 22, ans);
	cout <<  ans << std::endl;
	return 0;

}
