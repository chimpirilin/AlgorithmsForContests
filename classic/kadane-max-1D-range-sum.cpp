#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v;
    while(n--){
        int x;
        cin>>x;
        v.push_back(x);
    }

    int sm=0;
    int ans=0;

    for(int i = 0; i < v.size(); ++i){
        sm+=v[i];
        ans=max(ans,sm);
        if(sm<0)
            sm=0;
    }

    cout<<ans<<endl;

    return 0;
}