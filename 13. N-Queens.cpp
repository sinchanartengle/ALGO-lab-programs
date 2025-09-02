/*
Implement N Queen’s problem using Back Tracking
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to place queens on the board row by row
void queen(vector<vector<bool>>& board,int row);
// Function to check whether placing a queen at board[row][col] is safe
bool isSafe(vector<vector<bool>>& board,int row,int col);
// Function to print the board
void display(vector<vector<bool>>& board);

int main(){
    int n;
    cout<<"\nEnter the size of the board(N x N): ";
    cin>>n;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    // Start from the first row (row = 0)
    queen(board,0);
    return 0;
}

void queen(vector<vector<bool>>& board,int row){
    if(row==board.size()){
        display(board);
        cout<<"\n";
        return;
    }
    // Try placing a queen in each column of the current row
    for(int col=0;col<board.size();col++){
        //Check if placing Queen is Safe
        if(isSafe(board,row,col)){
            board[row][col]=true; // Place the queen
            queen(board,row+1);   //Move to the next row
            board[row][col]=false; //remove the queen and try next col
        }
    }

}
bool isSafe(vector<vector<bool>>& board,int row,int col){
    //Check for any queen in the same column
    for(int i=0;i<row;i++){
        if(board[i][col])
            return false;
    }
    //Check the upper-left diagonal for any queen
    int maxLeft=min(row,col);
    for(int i=1;i<=maxLeft;i++){
        if(board[row-i][col-i])
            return false;
    }
    // Check the upper-right diagonal for any queen
    int maxRight=min(row,(int)board.size()-col-1);
    for(int i=1;i<=maxRight;i++){
        if(board[row-i][col+i])
            return false;
    }
    return true;
}
void display(vector<vector<bool>>& board){
    for(auto row:board){
        for(auto element:row){
            element?cout<<"Q ":cout<<"X ";
        }
        cout<<"\n";
    }
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