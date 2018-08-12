#include <iostream>

using namespace std;

int a[18];

int sol(int n)
{
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    if(a[n] == 0){
         a[n]=sol(n-1)+sol(n-2)+2*sol(n-5)+2*sol(n-10);
         return a[n];
    }
    else
        return a[n];
}



int main()
{
    cout << sol(17);
    return 0;
}

