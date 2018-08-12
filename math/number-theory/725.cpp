#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	//int fl[10];
	set<char> s;
	for(int i=1234;i<=98765/n;++i){
		//memset(fl,0,sizeof(fl));
		bool no=false;
		auto x=n*i;
		auto s1=to_string(i);
		auto s2=to_string(x);
		for(auto c:s1){
			if(s.find(c)!=s.end()){
				no=!no;
				s.clear();
				break;
			}
			else
				s.insert(c);
		}

		if(!no){
			continue;
		}

		for(auto c:s2){
			if(s.find(c)!=s.end()){
				no=!no;
				s.clear();
				break;
			}
			else
				s.insert(c);
		}

		cout<<x<<" / "<<i<<" = "<<n<<endl;
	}
	return 0;
}