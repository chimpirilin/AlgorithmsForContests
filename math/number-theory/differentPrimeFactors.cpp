#include <bits/stdc++.h>

using namespace std;
#define MAX_N 100
long long numDiffPF[MAX_N+1];

void primeFactorsRange(){
memset(numDiffPF, 0, sizeof numDiffPF);
for (int i = 2; i < MAX_N; i++)
	if (numDiffPF[i] == 0)
		for (int j = i; j < MAX_N; j += i)
			numDiffPF[j]++;
}
int main(){
 	primeFactorsRange();
	for(int i = 0; i < MAX_N; ++i)
		cout << i << ": " <<  numDiffPF[i] << endl;
	return 0;
}