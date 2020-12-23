#include <iostream>

using namespace std;

long long x, y, d;
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

int main(){
	extendedEuclid(1097392385, 128943945);
	//cout << "25x+18y=d: " << "25*"<<x<<"+18*"<<y<<"="<<d<<std::endl;
	cout << x<<" "<<y;
	return 0;
}
