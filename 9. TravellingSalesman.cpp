/*
Given a 2d matrix cost[][] of size n where cost[i][j] denotes the cost of moving from city i to city j. 
The task is to complete a tour from city 0 (0-based index) to all other cities such that we visit each 
city exactly once and then at the end come back to city 0 at minimum cost.
*/
#include <iostream>
#include <vector>
using namespace std;

int tsp(vector<vector<int>>& cost);
int totalCost(int mask,int pos,int n,vector<vector<int>> &cost);
int main(){
    vector<vector<int>> mat={
        {0, 10, 15, 20}, 
        {10, 0, 35, 25}, 
        {15, 35, 0, 30}, 
        {20, 25, 30, 0}
    };
    int res=tsp(mat);
    cout<<res<<endl;
    return 0;
}

int tsp(vector<vector<int>>& cost){
    int n=cost.size();
    return totalCost(1,0,n,cost);
}
int totalCost(int mask,int pos,int n,vector<vector<int>> &cost){
    
}