struct data{
	int u;
	ll dis,cos;
	data(int aa, ll bb, ll cc){
		u=aa;
		dis=bb;
		cos=cc;
	}
	bool operator<(data other) const {
		if(dis<other.dis){
			return true;
		}else if(dis>other.dis){
			return false;
		}
		
		if(cos>other.cos){
			return true;
		}
		return false;
	}
};

int main(){
	
	priority_queue<data,vector<data>> pq;
	data a(1,2,3);
	data b(1,2,2);
	data c(2,3,3);
	data d(1,2,1);
	
	pq.push(a);
	pq.push(b);
	pq.push(c);
	pq.push(d);
	
	while(!pq.empty()){
		auto front=pq.top();
		pq.pop();
		cout<<front.u<<" "<<front.dis<<" " <<front.cos;cout<<endl;
	}
	
	return 0;
}
