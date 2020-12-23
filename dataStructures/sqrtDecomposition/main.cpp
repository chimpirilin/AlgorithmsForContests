const int tam=100000;

int a[tam+1];
int n;
int b[tam];
const int len=750;

void pre(){
    //don't compute the block size at runtime - make it const
    //int len = (int) sqrt (n + .0) + 1; // size of the block and the number of blocks
    //vector<int> b (len);
    for (int i=0; i<n; ++i)
        b[i / len] += a[i];
}
//0-indexed!
int query(int l, int r){
    int sum = 0;
    int c_l = l / len,   c_r = r / len;
    if (c_l == c_r){
        for (int i=l; i<=r; ++i)
            sum += a[i];
        return sum;
    }
    for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
        sum += a[i];
    for (int i=c_l+1; i<=c_r-1; ++i)
        sum += b[i];
    for (int i=c_r*len; i<=r; ++i)
        sum += a[i];
    return sum;
}

//change value of a[pos]=x
//O(qsrt(n)) for other operations such as min,GCD,etc...
void update(int pos, int x){
    int bl=pos/len;
    b[bl]-=a[pos];
    a[pos]=x;
    b[bl]+=a[pos];
}

int main(){

}
