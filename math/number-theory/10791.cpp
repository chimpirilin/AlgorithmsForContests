#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int c=1;
	while(cin>>n&&n){
		long long mn=2147483649;
		int lim=sqrt(n);
		for(int i=1;i<=lim++i){
			if(n%i==0){
				auto aux=n/i;
				auto g=__gcd(i, aux);
				if(g==n)
					if(i+aux<mn)
						mn=i+aux;
			}
		}

		cout << "Case "<<c<<" "<<mn<<std::endl;

		++c;
	}
}