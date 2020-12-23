#include <iostream>
#include <vector>

using namespace std;

long long x, y, d;
std::vector<long long> sol;

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
//Modular linear equation solver, ax=b(modn)
bool modEq(long long a, long long b, long long n){
	extendedEuclid(a, n);
	if(b%d==0){
		long long x0 = (x*(b/d))%n;
		cout << "x0:" << x0 << endl;
		for (int i = 0; i < d; ++i){
			long long ans = (x0+i*(n/d))%n;
			sol.push_back(ans);
		}
		return true;
	}

	return false;
}
//Sometimes modEq returns negative residues
void negToPos(long long &x, long long mod){
	x=(mod+(x%mod))%mod;
}

int main(){
	if(modEq(14, 30, 100)){
		for(auto &x : sol){
			if(x < 0)
				negToPos(x, 100);
			cout << x << endl;
		}
	}else{
		cout << "No solutions!" << std::endl;
	}
	return 0;
}
