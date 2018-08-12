#include <bits/stdc++.h>

using namespace std;

unsigned long long cnk(unsigned long long nn, unsigned long long kk) {
	const int maxn = nn;
	unsigned long long C[maxn+1][maxn+1];
	for (int n=0; n<=maxn; ++n) {
	    C[n][0] = C[n][n] = 1;
	    for (int k=1; k<n; ++k)
	        C[n][k] = C[n-1][k-1] + C[n-1][k];
	}
	return C[nn][kk];
}

/*int cnk(unsigned long long n, unsigned long long k) {
    long double res = 1;
    for (unsigned long long i=1; i<=k; ++i)
        res = res * (n-k+i) / i;
    return (int) (res + 0.01);
}*/

int main(){
	auto x = cnk(67, 34);
	cout << x << endl;
	return 0;
}
