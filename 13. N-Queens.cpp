/*
Implement N Queen’s problem using Back Tracking
*/
#include<iostream>
using namespace std;
#define MAX 10

int board[MAX],i,j;

bool isSafe(int row,int col){
    for(i=0;i<row;i++){
        if (board[i] == col || (board[i] - col) == (i - row) || (board[i] - col) == (row - i)) {
            return false;
        }
    }
    return true;
}

void print(int n){
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            if (board[i] == j)
                cout <<" Q ";
            else
                cout <<" - ";
        }
        cout <<"\n";
    }
    cout <<"\n";
}

void nqueen(int row,int n){
    if(row==n){
        print(n);
        return;
    }
    for(int col=0;col<n;col++){
        if(isSafe(row,col)){
           board[row]=col;
           nqueen(row+1,n);
        }
    }
}

int main(){
    int n;
    cout<<"Enter the No. of Queen's :";
    cin>>n;
    nqueen(0,n);
}
 

/*
Rules:
1) Only one queen per row.
2) Only one queen per column.
3) No two queens can be in the same diagonal (either left or right)

Approach:
We use recursion and backtracking to explore all possible placements row by row.
At each step, we try placing a queen in every column of the current row and
proceed to the next row if the placement is safe. If not, we backtrack and try the next column.

Recursive Realtion: T(N)= N*T(N-1) +O(n^2)
SC : O(N^2) for board +O(N) for recursion
TC: (N*)T(N-1)~N!
*/
