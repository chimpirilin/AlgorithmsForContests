#include <bits/stdc++.h>

using namespace std;

int n;

template<typename T>
void subsets(vector<T> &v){
	auto n=v.size();
	auto lim=(1<<n);
	for(int i=0;i<lim;++i){
		auto cur=0;
		for(int j=0;j<n;++j){
			//Test if jth bit is on
			if(i&(1<<j)){
				cur+=v[j];
				if(cur==n){
					cout<<"YES"<<"\n";
					return;
				}
			}

			if(cur==n){
				cout<<"YES"<<"\n";
				return;
			}
		}
	}

	cout<<"NO"<<"\n";
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int tam;
		cin>>n;
		cin>>tam;
		vector<int> v;
		for(int i=1;i<tam;++i){
			int tmp;
			cin>>tmp;
			v.push_back(tmp);
		}
		subsets(v);
	}
	return 0;
}