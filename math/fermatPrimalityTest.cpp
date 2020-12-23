#include <iostream>

using namespace std;

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

/* Fermat's test for checking primality, the more iterations the more is accuracy */
bool Fermat(long long p,int iterations){
    if(p == 1){
        return false;
    }
    for(int i=0;i<iterations;i++){
        long long a = rand()%(p-1)+1; 
        if(exp(a,p-1,p) != 1){ 
            return false;
        }
    }
    return true;
}

int main(){
	if(Fermat(100000007,10))
		cout << "Is prime!";
	else
		cout << "Is not prime!";

	return 0;
}
