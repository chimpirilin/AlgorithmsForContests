#include <iostream>
#include <string>
#include <algorithm>
   
using namespace std;

//It computes the next lexicographical permutation of a string
//returns false if the given string is the last lexicographical permutation, true otherwise
//And store the result in the variable result.
  
bool n_permutation(string p, string &result)
{
	result = p;
    int n = p.size()-1;
    int j = n-1;
    int k = n;
   
    for(; result[j] > result[j+1]; --j);
    if(j < 0) 
        return false;
    for(; result[j] > result[k]; --k);

    swap(result[j], result[k]);

    int r = n;
    int s = j+1;

    while(r > s)
    {
        swap(result[r], result[s]);
        r--;
        s++;
    }
    return true;
}

int main()
{
    string s="1234";
    cout << s << endl;
    while(n_permutation(s, s))
       cout << s << endl;
    return 0;
}
