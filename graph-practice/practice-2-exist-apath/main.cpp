#include <bits/stdc++.h>
#define ii pair<int,int>
#define vii vector<ii>
#define tam 1000
#define fff first
#define sss second

using namespace std;

vii adl[tam];
bool visited[tam];

bool existpath(int v, int w,string ans){
	if(v==w) {
		ans.erase(ans.end()-2,ans.end());
		return true;
	}
	visited[v]=true;
	
	for(auto x:adl[v]){
		if(!visited[x.fff])
		if(existpath(x.fff,w,ans+to_string(x.fff)+"->")) return true;
	}
	return false;	
}
 
int here=3, nothere=1;
//A path that starts from v, ends at w, passes through here, and does not pass throught nothere
bool existpath2(int v, int w,string ans,bool xx){
	if(v==w) {
		if(xx==true){
			ans.erase(ans.end()-2,ans.end());
			cout<< "trueans: "<<ans<<endl;
			return true;
		}
		return false;
	}
	visited[v]=true;
	bool fl=false;
	for(auto x:adl[v]){
		if(!visited[x.fff]){
			cerr<<x.fff<<endl;
			if(x.fff==here){
				xx=true;
				fl=true;
			}
			if(xx){
				if(existpath2(x.fff,w,ans+to_string(x.fff)+"->",true)) return true;
			}
			else{
				
				if(existpath2(x.fff,w,ans+to_string(x.fff)+"->",false)) return true;
			}
			if(fl){
				fl=false;
				xx=false;
			}
			
		}
	}
	return false;	
}


int main(){
	adl[0].push_back({1,2});
	adl[0].push_back({2,3});
	adl[0].push_back({6,3});
	adl[0].push_back({5,3});
	adl[1].push_back({0,3});
	adl[1].push_back({2,3});
	adl[1].push_back({3,3});
	adl[2].push_back({1,3});
	adl[2].push_back({3,3});
	adl[2].push_back({4,3});
	adl[2].push_back({0,3});
	adl[3].push_back({1,3});
	adl[3].push_back({2,3});
	adl[3].push_back({4,3});
	adl[4].push_back({5,3});
	adl[4].push_back({6,3});
	adl[4].push_back({3,3});
	adl[4].push_back({2,3});
	adl[5].push_back({0,4});
	adl[5].push_back({4,4});
	adl[6].push_back({0,3});
	adl[6].push_back({4,3});
	int a=0;
	int b=6;
	memset(visited,false,sizeof visited);
	visited[nothere]=true;
	existpath2(a,b,to_string(a)+"->",false);
	//if(existpath(a,b,to_string(a)+"->")) cout<<"Exist a path from "<<a<<" to " <<b;
	//else cout<<"There is not a path from "<<a<< " to "<<b;
	cout<<endl;
	return 0;
}
