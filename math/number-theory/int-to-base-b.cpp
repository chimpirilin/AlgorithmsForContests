#include <bits/stdc++.h>

using namespace std;

string s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

//x=(mod+(x%mod))%mod; //Not tested but it should work!

string convert(int n, int b){
    string res="";
    while(n>0){
        int tmp=(b+(n%b))%b;
        
        //char c='0'+tmp;

        //cerr<<n<<" "<<c<<endl;
        res.insert(res.begin(),s[tmp]);
        n/=b;
    }

    return res;
}

int main(){
    int x;
    cin>>x;
    cerr<<convert(18,16);
    return 0;
}
