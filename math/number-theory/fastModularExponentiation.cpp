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

long long expmod(long long a, long long b, long long c){
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

int main(){
	cout << expmod(2, 77503, 131241);
	return 0;
}
