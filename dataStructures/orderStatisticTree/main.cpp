#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //--------> important header!
#include <ext/pb_ds/tree_policy.hpp>    //--------> important header!
using namespace  __gnu_pbds;           //--------> important namespace!
typedef tree<int,null_type,less<int>,//key,mapped type, comparator
    rb_tree_tag,tree_order_statistics_node_update> myset;
//typedef tree<pair<ll,int>,null_type,less<pair<ll,int>>, //Use this when you need a multiset
//    rb_tree_tag,tree_order_statistics_node_update> myset; //Use insert({x,++cnt}) to get unique elements

//find_by_order(i) devuelve iterador al i-esimo elemento, 0-indexed!
//That is, find_by_order returns the first element
//order_of_key(k): devuelve la pos del lower bound de k
//Ej: 12, 100, 505, 1000, 10000.
//order_of_key(10) == 0, order_of_key(100) == 1,
//order_of_key(707) == 3, order_of_key(9999999) == 5

int main(){
	myset s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	for(auto item:s){
		cout<<item<<" ";
	}
	cout<<endl;
	cout<<*s.find_by_order(3);cout<<endl;
	
    return 0;
}
