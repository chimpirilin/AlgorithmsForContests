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

void firstdigits(a, b){
	long double x=(b*1.0)*log(a);
	long double ex=x-trunc(x);
	auto ans=pow(10, ex);
	cout << ans;
}

int main(int argc, char const *argv[])
{
	int t;
	while(t--){
		long long a, b;
		cin>>a>>b;
		firstdigits(a, b);
	}
	return 0;
}