#include <bits/stdc++.h>
#define tam 100
using namespace std;

int v[tam];


//typical binary search, returns -1 if it's not in the array else returns the position of target
int binarysearch(int start, int end, int target){
	//cout<<"binarysearc"<<endl;
	while(start<=end){
		int mid=(start+end)/2;
		//cout<<start<< " "<<end<< " "<<mid<<endl;
		if(v[mid]==target) return mid;
		if(target<v[mid]) end=mid-1;
		else start=mid+1;
	}
	//cout<<"binarysearch ends"<<endl;
	return -1;
}

//First ocurrence of target, similar to lower_bound
int firstocurrence(int start,int end, int target){
	//cout<<"firstocurrence"<<endl;
	int mid;
	while(start<end){
		mid=(start+end)/2;
		if(target==v[mid]) end=mid;
		else if(target<v[mid]) end=mid-1;
		else start=mid+1;
		//cout<<start<< " "<<end<< " "<<mid<<endl;
	}
	//cout<<"firstocurrence ends"<<endl;
	return (v[start]==target)?start:-1;
}

//Last ocurrence of target, similar to upper_bound
int lastocurrence(int start,int end, int target){
	//cout<<"lastocurrence"<<endl;
	int mid;
	//cout<<start<<" " <<end<< " "<<(start+end)/2<<endl;
	while(start<end){
		mid=((start+end)+1)/2;
		if(target==v[mid]) start=mid;
		else if(target>v[mid]) start=mid+1;
		else end=mid-1;
	//	cout<<start<<" " <<end<< " "<<(start+end)/2<<endl;
	}
	
	//cout<<"lastocurrence ends"<<endl;
	return (v[end]==target)?end:-1;
}

//If it finds it, returns the number
//else returns the closest number
int closest(int start, int end, int target){
	//cout<<"closest"<<endl;
    int mid,ans=v[0];
    while(1){
        if(end-start==1){
            if(abs(v[start]-target)<abs(target-v[end]))
                ans=v[start];
            else
                ans=v[end];
            break;
        }
        mid=(start+end)/2;
        if(v[mid]>target)
            end=mid;
        else if(v[mid]<target)
            start=mid;
        else{
            ans=target;
            //cout<<"ans: "<<ans<<endl;
            break;
        }
    }
	//cout<<"closest end"<<endl;
    return ans; 
}

int main(){
	int n;cin>>n;
	for (int i = 0; i < n; i++){
		cin>>v[i];
	}
	
	sort(v,v+n);
	for (int i = 0; i < n; i++){
		cout<< v[i]<< " ";
	}
	cout<<endl;
	int t;cin>>t;while(t--){
		int target;cin>>target;
		cout<<"target: "<<target<<endl;
		auto res=binarysearch(0,n-1,target);
		if(res!=-1){
			cout<<target<< " found at position "<<res<<endl;
		}else cout<<target<< " is not in the array"<<endl;
		res=closest(0,n-1,target);
		cout<<"closest to "<<target<< " is "<< res<<endl;
		res=firstocurrence(0,n-1,target);
		if(res!=-1) cout<<"First ocurrence of "<< target<< " is " <<res<<endl;
		else cout<<target<< " is not in the array"<<endl;
		res=lastocurrence(0,n-1,target);
		if(res!=-1) cout<<"Last ocurrence of "<< target<< " is " <<res<<endl;
		else cout<<target<< " is not in the array"<<endl;
	}
	
	
	return 0;
}
