#include <bits/stdc++.h>

using namespace std;

int grid[5][5]
int n;

bool solve(int rw,int cl){
    if(grid[rw][cl]=='X') return false;
    for(int i = 0; i < n; ++i){
        if(grid[rw][i]=='X') break;
        else if(grid[rw][i]=='o') return false;
    }

    for(int i = 0; i < n; ++i){
        if(grid[i][col]=='X') break;
        else if(grid[i][col]=='o') return false;
    }

    grid[rw][cl]='o';

    return true;
}

//We generate every configuration(combinations) 
void solve(vector<int> &v){
    auto tam=v.size();
    auto lim=(1<<tam);
    int mx=0;
    for(int i=0;i<lim;++i){
        int cur=0;

        for(int resi = 0; resi < n; ++resi){
            for(int resj = 0; resj < n; ++resj){
                if(grid[i][j]=='o')
                    grid[i][j]='.';
            }
        }

        for(int j=0;j<tam;++j){
            //Test if jth bit is on
            if(i&(1<<j)){
                int rw=j/n;
                int cl=j%n;
                if(check(rw,cl)){
                    ++cur;
                }else break;

            }
            if(cur>mx)
                mx=cur;

        }
    }
}

int main()
{
    while(cin>>n&&n){
        vector<int> v;
        int c=0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin>>grid[i][j];
                v.push_back(c++);
            }
        }

        solve(v);

    }


    return 0;
}