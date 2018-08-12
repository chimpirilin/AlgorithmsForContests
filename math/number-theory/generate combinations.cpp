#include <bits/stdc++.h>

using namespace std;

template<typename T>
void subsets(vector<T> &v){
	auto n=v.size();
	auto lim=(1<<n);
	for(int i=0;i<lim;++i){
		for(int j=0;j<n;++j){
			//Test if jth bit is on
			if(i&(1<<j))
				cout << v[j]<<" ";
		}
		cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	vector<int> v;
	for(int i=1;i<=10;++i)
		v.push_back(i);
	subsets(v);
	return 0;
}