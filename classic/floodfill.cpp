#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define lob lower_bound
#define upb upper_bound
#define ff first
#define ss second
#define beg begin
#define sz size
#define clear(a,b) memset(a,b,sizeof a)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


char line[150], grid[150][150];
int TC, R, C, row, col;

int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};


int floodfill(int r, int c, char c1, char c2) {
  if (r<0 || r>=R || c<0 || c>=C) return 0;
  if (grid[r][c] != c1) return 0; // we want only c1
  grid[r][c] = c2;
  int ans = 1;
  for(int i=0; i<8;++i)
    ans += floodfill(r + dr[d], c + dc[d], c1, c2);
  return ans;
}

int main(){
	ios::sync_with_stdio(false);
	
	
	
	return 0;
}
