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

bool Miller(long long p,int iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=exp(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=multmod(mod,mod,p);
            cout << mod << " " << temp << endl;
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}

int main(){
    if(Miller(999999937,18))
        cout << "Is prime!";
    else
        cout << "Is not prime!";
    return 0;
}
