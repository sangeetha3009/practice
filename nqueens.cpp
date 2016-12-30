#include <iostream>
using namespace std;

#define n 8

bool issafe(int board[n][n],int row,int col){
	int r,c;
	r=row;
	for(c=0;c<col;c++){
		if (board[r][c] == 1)
			return false;
	}
	for(r=row,c=col;r<n && c >= 0;r++,c--){
		if(board[r][c] == 1)
			return false;
	}
	for(r=row,c=col;r>=0 && c>= 0;r--,c--){
		if(board[r][c] == 1)
			return false;
	}
	return true;
}

bool nqueens(int board[n][n],int col){
        if(col >= n)
	    return true;
	for(int i=0;i<n;i++){
		if(issafe(board,i,col)){
   			board[i][col] =1;
   			if(nqueens(board,col+1))
   				return true;
   			board[i][col] =0;
		}

   	}
   return false;
}

int main(){
	int board[n][n]={0};
        for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                   cout<<board[i][j]<<" ";
             }
             cout<<endl;
	}
	if (nqueens(board,0)){
		cout<<" Solution "<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		
	}
	else
		cout<<"No Solution ";
	return 0;
}
