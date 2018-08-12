#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vii vector<pii>
#define vi vector<int>
#define tam 1000


//vector<vii> adl;
vii adl[tam];


int main(){
	adl[0].push_back({1,2});
	adl[0].push_back({2,3});
	adl[2].push_back({1,3});
	adl[3].push_back({4,3});
	adl[3].push_back({5,4});
	for(int i=0;i<tam;++i){
		if(adl[i].empty()) continue;
		for(auto x:adl[i]){
			cout<<i<<" -> "<<x.first<<", weight: " <<x.second<<endl;;
		}
	}
	
	return 0;
}
