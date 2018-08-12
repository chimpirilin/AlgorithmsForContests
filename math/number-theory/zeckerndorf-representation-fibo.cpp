#include <bits/stdc++.h>
using namespace std;
 
// Returns the greatest Fibonacci Numberr smaller than
// or equal to n.
int nearestSmallerEqFib(int n)
{
    // Corner cases
    if (n == 0 || n==1)
       return n;
 
    // Find the greatest Fibonacci Number smaller
    // than n.
    int f1 = 0, f2 = 1, f3 = 1;
    while (f3 <= n)
    {
        f1 = f2;
        f2 = f3;
        f3 = f1+f2;
    }
    return f2;
}
 
// Prints Fibonacci Representation of n using
// greedy algorithm
void printFibRepresntation(int n)
{
    while (n>0)
    {
        int f = nearestSmallerEqFib(n);
 
        cout << f << " ";
        n = n-f;
    }
}
 
int main()
{
    int n = 30;
    cout << "Non-neighbouring Fibonacci Representation of "
        << n << " is \n";
    printFibRepresntation(n);
  }