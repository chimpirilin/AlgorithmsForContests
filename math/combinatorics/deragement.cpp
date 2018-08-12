#include <bits/stdc++.h>
#define maxn 20 //Using a greater value will cause overflow!

using namespace std;

long long der[maxn+1];

void calc(){
	der[0]=1;
	der[1]=0;
	der[2]=1;
	for (long long i = 3; i < maxn+1; i++){
		der[i]=(i-1)*(der[i-1]+der[i-2]);
	}
}

int main(){
	calc();
	for (int i = 0; i < maxn+1; i++)
	{
		cout<<"der("<<i<<"): "<<der[i]<<endl;
	}
	cout<<endl;
	
	return 0;
}
