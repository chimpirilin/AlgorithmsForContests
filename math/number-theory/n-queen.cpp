#include <bits/stdc++.h>

using namespace std;

const int n=4;
int board[n][n];

void printSol(){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)
			cout<<board[i][j];
		cout<<endl;
	}
	cout<<endl;
}

bool validPos(int row, int col){
	//Checking the left side of the row
	for(int i=0;i<col;++i)
		if(board[row][i])
			return false;
	//Checking upper diagonal on then left
	for(int i=row,j=col;i>=0&&j>=0;--i, --j)
		if(board[i][j])
			return false;
	//Checking upper diagonal on then left
	for(int i=row,j=col;i<n&&j>=0;++i, --j)
		if(board[i][j])
			return false;
	return true;
}

bool solve(int col){
	if(col>=n){
		printSol();
		return true; //All the queens have been placed!
	}
	for(int row=0;row<n;++row){
		if(validPos(row,col)){ //We can place the queen in this position
			board[row][col]=1;
			//Now we are gonna place the rest of the queens
			solve(col+1);
			board[row][col]=0; //Not a valid position... Backtrack!
		}
	}
	return false; //We couldnt place a queen in any row of this column
}

int main(int argc, char const *argv[])
{
	memset(board, 0, sizeof board);
	solve(0);
	return 0;
}