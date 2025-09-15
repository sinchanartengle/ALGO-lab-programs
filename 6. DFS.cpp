/*
7)b. Check whether a given graph is connected or not using DFS method.   
*/
#include<iostream>
using namespace std;

int visited[10],n,cost[10][10],count=0,i,j;

void dfs(int source){
    int i;
    visited[source]=1;
    count++;
    for(i=1;i<=n;i++){
        if((cost[source][i]==1)&&(visited[i]==0)){
            dfs(i);
        }
    }
}

int main(){
    int source;
    cout<<"Enter no. of vertices :";
    cin>>n;
    cout<<"Enter the cost matrix (1 for edge & 0 for no-edge)\n";
     for(i=1;i<=n;i++){
       for(j=1;j<=n;j++){
           cin>>cost[i][j];
       }
    }
    for(i=1;i<=n;i++)
        visited[i]=0;
    
    cout<<"Enter the Source Vertex :";
    cin>>source;

    dfs(source);
    
    if (count == n)
      cout <<"The graph is connected";
    else
      cout <<"The graph is not connected";
}

/*
---------------------------Complexity---------------------
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(E)

--------------------------algorithm for this question-------------------------
1) Initialize all vertices as unvisited.
2) For each vertex in the graph:
   - If the vertex is not visited, start a DFS from that vertex.
   - Mark the vertex as visited.
   - Recursively visit all its adjacent unvisited vertices.
3) Count how many times DFS is called from unvisited vertices.
4) If this count is 1, the graph is connected; otherwise, it is disconnected.


-----------------------------------Algorithm for DFS-------------------------------
1)Start by put the vertex on top of a stack.
2)Take the top item of the stack and add it to the visited list.
3)Create a list of that vertex's adjacent nodes. Add the ones which aren't in the visited list to the top of the stack.
4)Keep repeating steps 2 and 3 until the stack is empty.
*/
