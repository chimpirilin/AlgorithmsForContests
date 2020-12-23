#include <bits/stdc++.h>

using namespace std;

int numDiffPF[1000009];

void primeFactorsRange(int lim){
	for (int i = 2; i < lim; i++)
		if (numDiffPF[i] == 0)
			for (int j = i; j < lim; j += i)
				numDiffPF[j]++;
}
int main(){
 	primeFactorsRange(100);
	for(int i = 0; i < 100; ++i)
		cout << i << ": " <<  numDiffPF[i] << endl;
	return 0;
}