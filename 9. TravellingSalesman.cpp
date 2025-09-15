/*
Given a 2d matrix cost[][] of size n where cost[i][j] denotes the cost of moving from city i to city j. 
The task is to complete a tour from city 0 (0-based index) to all other cities such that we visit each 
city exactly once and then at the end come back to city 0 at minimum cost.
*/
#include<iostream>
using namespace std;

int c[100][100],s,ver;
float optimum=999,sum;

int swap(int v[],int i,int j){
    int t;
    t=v[i];
    v[i]=v[j];
    v[j]=t;
}

int tsp (int v[],int n,int i ){
    int sum1,j,k;
    if(i==n){
        if(v[0]==s){
            for(j=0;j<n;j++)
                sum1=0;
            for(k=0;k<n-1;k++){
                sum1=sum1+ c[v[k]][v[k+1]];
            }
            sum1=sum1+c[v[n-1]][s];
            if(sum1 < optimum)
               optimum=sum1;
        }
    }
    else {
        for(j=i;j<n;j++){
           swap(v,i,j);
           tsp(v,n,i+1);
           swap(v,i,j);}
    }
}

void approx(int ver){
    int min, p, i, j, vis[20], from;
    for (i=1;i<=ver;i++)
        vis[i]=0;
    vis[s]=1;
    from=s;
    sum=0;
    for (j=1;j<ver;j++){
        min = 999;
        for (i=1;i<=ver;i++)
            if (vis[i] != 1 && c[from][i] < min && c[from][i] != 0)
            {
                min = c[from][i];
                p = i;
            }
        vis[p]= 1;
        from= p;
        sum=sum + min;
    }
    sum =sum+c[from][s];
}

int main(){
    int v[100],ver,n,i,j;
    cout <<"Enter No. of vertices :";
    cin>>ver;
    for(i=0;i<ver;i++)
    v[i]=i+1;
    cout<<"Enter the Cost matrix (999 for infinity)\n";
    for(i=1;i<=ver;i++)
      for(j=1;j<=ver;j++)
        cin>>c[i][j];
    cout<<"Enter Source :";
    cin>> s;
    tsp(v,ver,0);
    cout << "\nOptimum solution is = "<<optimum<<"\n"; 
    approx(ver);
    cout <<"Solution with Approximation Algorithm is = " << sum << "\n";
    cout <<"The approximation val is = " << ((sum / optimum) - 1) * 100 << "%";
}


/*Algorithm for Travelling Salesman Problem (TSP)
1.Input
Number of vertices ver.
Cost adjacency matrix c[ver][ver] (use 999 to represent no edge/infinity).
Starting vertex s.
2.Part 1: Exact (Optimum) Solution using Permutations
Represent the vertices in an array v[].
Generate all possible permutations of the vertices.
Ensure the path starts at the given source s.
For each permutation (Hamiltonian cycle):
Compute the total cost of the path:
cost = c[v[0]][v[1]] + c[v[1]][v[2]] + ... + c[v[n-1]][s]
Compare with the current best (minimum).
If the new cost is smaller, update optimum.
After checking all permutations, optimum contains the minimum cost tour.
3.Part 2: Approximation Solution (Nearest Neighbor Heuristic)
Mark all vertices as unvisited.
Start at the source vertex s and mark it as visited.
Repeat until all vertices are visited:
From the current vertex, choose the nearest unvisited neighbor (smallest cost edge).
Move to that neighbor and add the edge cost to sum.
Mark the neighbor as visited.
After visiting all vertices, return to the source s and add this cost to sum.
This gives the approximate solution.
4.Output
Print the optimum solution cost (optimum) from exact algorithm.
Print the approximate solution cost (sum) from heuristic.
Compute the approximation error as:
((sum / optimum) - 1) * 100 %
which shows how far the heuristic solution is from the optimum.*/
