#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int l[MAX_N], l_id[MAX_N], p[MAX_N];
int n;

vector<int> longestIS(int a[]){
    int lis = 0, lis_end = 0;
    for (int i = 0; i < n; ++i){
        int pos = lower_bound(l, l + lis, a[i]) - l;
        l[pos] = a[i];
        l_id[pos] = i;
        p[i] = pos ? l_id[pos - 1] : -1;
        if (pos + 1 > lis){
            lis = pos + 1;
            lis_end = i;
        }
    }
    vector<int> v;
    int x=lis_end;
    for (; p[x] >= 0; x = p[x])
       v.insert(v.begin(),a[x]);
    v.insert(v.begin(),a[x]);
    return v;
}

int main(){
    cin>>n;
    int a[n];
    for(int i = 0; i < n; ++i){
        cin>>a[i];
    }
    for(auto item : longestIS(a)){
        cout<<item<<" ";
    }
    return 0;
}
