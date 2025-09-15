/*
12. Find Minimum Cost Spanning Tree of a given undirected graph using Prim’s algorithm 
*/

#include<iostream>
using namespace std;
#define MAX 10

int cost[MAX][MAX];

void prims(int cost[MAX][MAX],int n){
    int a=0,b=0,u=0,v=0;
    int i,j,min,mincost=0;
    int ne=1;  //ne = no. of edges
    int visited[10]={0};
    visited[1]=1;

    while(ne<n){
       
       for(i=1,min=999;i<=n;i++){
          for(j=1;j<=n;j++){
               if(cost[i][j]<min){
                  if(visited[i]!=0){
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                  }
               }
          }
       }
    if(visited[u]==0 || visited[v]==0){
            cout << "\nEdge-" <<ne++<< " (" << a << "," << b << ") : " << min;
            mincost += min;
            visited[b]=1;
       }
       cost[a][b]=cost[b][a]=999;
   }
   cout<<"\nMinimum cost :"<<mincost;
}

int main(){
    int n,i,j;
    cout<<"Enter the no. of vertices :";
    cin>>n;
    cout<<"Enter the cost matrix (999 for no-edge and self loops)\n";
    for(i=1;i<=n;i++){
       for(j=1;j<=n;j++){
           cin>>cost[i][j];
       }
    }
    prims(cost,n);
}

/*
------------------------------------------------Algorithm------------------------------------------
Step 1: Determine an arbitrary vertex as the starting vertex of the MST. We pick 0 in the below diagram.
Step 2: Follow steps 3 to 5 till there are vertices that are not included in the MST (known as fringe vertex).
Step 3: Find edges connecting any tree vertex with the fringe vertices.
Step 4: Find the minimum among these edges.
Step 5: Add the chosen edge to the MST. Since we consider only the edges that connect fringe vertices with the rest, we never get a cycle.
Step 6: Return the MST and exit

TC: O(E log V)
SC: O(V + E)
*/
