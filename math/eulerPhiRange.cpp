#include <bits/stdc++.h>

using namespace std;
vector<long long> euler;

void eulerPhiRange(int lim){
	euler.reserve(lim+1);
	for (int i = 2; i <= lim; i++)
		euler[i] = i;
	for (int i = 2; i <= lim; i++)
		if (euler[i] == i)
			for (int j = i; j <= lim; j += i)
				euler[j] = (euler[j]/i)*(i-1);
}
int main(){
 	eulerPhiRange(300);
	for(int i = 0; i < 300; ++i)
		cout << i << ": " <<  euler[i] << endl;
	return 0;
}