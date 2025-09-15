/*
7)a. Print all the nodes reachable from a given starting node in a digraph using BFS 
method. 
*/
#include <iostream>
using namespace std;

void bfs(int cost[20][20],int source,int visited[20],int n){
    int queue[20], u, v;
    int f= 0;
    int r= -1;
    queue[++r]=source;
    while (f<=r){
        u=queue[f++];
        for (v=1;v<=n;v++){
            if (cost[u][v] == 1&&visited[v] == 0){
                queue[++r]=v;
                visited[v]=1;
            }
        }
    }
}

int main(){
    int n, cost[20][20], i, j, visited[20], source;
    cout <<"Enter the number of vertices:";
    cin >>n;
    cout <<"Enter the cost matrix (1 for edge & 0 for no-edge):\n";
    for(i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            cin >> cost[i][j];
    for(i=1;i<=n;i++)
        visited[i]=0;
    cout <<"Enter the source node:";
    cin >> source;
    visited[source] = 1;
    bfs(cost, source, visited, n);
    for (i=1;i<=n;i++){
        if (visited[i] != 0)
            cout<<"\nNode " << i << " is reachable";
        else
            cout <<"\n Node " << i << " is not reachable";
    }
}

/*
-----------------------------------Algorithm-------------------------------
1)Start by putting any one of the graph's vertices at the back of a queue.
2)Take the front item of the queue and add it to the visited list.
3)Create a list of that vertex's adjacent nodes. Add the ones which aren't 
    in the visited list to the back of the queue.
4)Keep repeating steps 2 and 3 until the queue is empty.

----------Complexity-------------
Time Complexity: O(V + E)  
Auxiliary Space: O(V) 

Each of the V vertices is visited once, and all E edges are explored exactly once during traversal. 
So, the total time is proportional to the number of vertices plus edges. We use a visited array, a 
queue, and a result list — all of which store up to V elements in the worst case, giving total 
auxiliary space of O(V).
*/
