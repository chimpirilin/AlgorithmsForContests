//In combinatorial mathematics, a derangement is a permutation of the 
//elements of a set, such that no element appears in its original position. 
constexpr int tam=1000009;
constexpr int mod=1000000007;
ll derangement[tam];
void prec(){
    derangement[0]=1;
    derangement[1]=0;
    F(i,2,tam,1){
		derangement[i]=((ll)(i-1))*((derangement[i-1]+derangement[i-2])%mod);
		derangement[i]%=mod;
    }
}


