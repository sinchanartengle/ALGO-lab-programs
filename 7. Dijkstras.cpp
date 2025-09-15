/*
From a given vertex in a weighted connected graph, find shortest paths to other vertices 
using Dijkstra’s algorithm. 
*/
#include<iostream>
using namespace std;

void dij(int cost[10][10],int source,int n,int visited[10],int dis[10]){
    int i,j,min,u,w;

    for(i=1;i<=n;i++){
        visited[i]=0;
        dis[i]=cost[source][i];
    }
    visited[source]=1;
    dis[source]=0;

    for(j=2;j<=n;j++){
          min=999;
        for(i=1;i<=n;i++){
            if(!visited[i]){
                if(dis[i]<min){
                    min=dis[i];
                    u=i;
                }
            }
        }
        visited[u]=1;
        for(w=1;w<=n;w++){
            if(cost[u][w]!=999 && visited[w]==0){
                if(dis[w]> cost[u][w]+dis[u])
                  dis[w]=cost[u][w]+dis[u];
            }
        }
    }
}

int main(){
    int source,cost[10][10], n,i,j,visited[10],dis[10];

    cout<<"Enter the No. of vertices :";
    cin>>n;
     cout<<"Enter the cost matrix (0 for self loop & 999 for no edge) \n";
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
        cin>>cost[i][j];
       }
    }
    cout<<"Enter the source :";
    cin>>source;

    dij(cost,source,n,visited,dis);

    for(i=1;i<=n;i++){
        if(i!=source){
            cout<<"\nShortest path from "<<source<<" --> "<< i<<" is "<<dis[i];
        }
    }
}

/*
Output:-
Enter the No. of vertices :5
Enter the cost matrix (0 for self loop & 999 for no edge) 
0 6 999 1 999
6 0 5 2 2
999 5 0 999 5
1 2 999 0 1
999 2 5 1 0
Enter the source :1

Shortest path from 1 --> 2 is 3
Shortest path from 1 --> 3 is 7
Shortest path from 1 --> 4 is 1
Shortest path from 1 --> 5 is 2
*/


/*Algorithm (Dijkstra’s Shortest Path)
1.Input
Number of vertices n.
Cost adjacency matrix cost[n][n], where:
cost[i][j] = 0 for self-loops.
cost[i][j] = 999 (infinity) if there is no edge.
The source vertex source.
2.Initialization
Create arrays dis[] (to store shortest distance from source to each vertex) and visited[] (to track visited vertices).
Set dis[i] = cost[source][i] for all vertices i.
Mark dis[source] = 0 (distance to itself is zero).
Mark all vertices as unvisited: visited[i] = 0.
Mark the source as visited: visited[source] = 1.
3.Iterative Process (Repeat n-1 times)
Find the unvisited vertex u that has the minimum distance value in dis[].
Mark this vertex u as visited.
For each vertex w adjacent to u:
If w is unvisited and there is an edge u → w,
Update the distance if a shorter path is found:
if dis[w] > dis[u] + cost[u][w]  
    then dis[w] = dis[u] + cost[u][w]
4.Output
After all iterations, dis[i] contains the shortest distance from source to vertex i.
Print the shortest paths for all vertices except the source itself.*/
