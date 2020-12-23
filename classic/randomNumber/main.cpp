int main(){
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> uid(1,100);
	for(int i=0; i<20;++i){
		cout<<rng()<<" "; //random number
	}
    cout<<endl;
    cout<<uid(rng); //random number (1,100), inclusive!
	return 0;
}
