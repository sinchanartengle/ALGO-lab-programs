#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
vector<int> bellman_ford(int V,vector<vector<int>>& edges,int S);
int main(){
    int V=4;
     vector<vector<int>> edges={
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    /*
    --example for -ve cycle--
    {0, 1, 1},
    {1, 2, -1},
    {2, 3, -1},
    {3, 0, -1}
    */
    };
    int source=0;
    vector<int> result=bellman_ford(V,edges,source);
    for(int i=0;i<V;i++){
        cout<<result[i]<<" ";
    }
}
vector<int> bellman_ford(int V,vector<vector<int>>& edges,int S){
    vector<int> distance(V,INT_MAX);
    distance[S]=0;
    for(int i=0;i<V-1;i++){
        for(auto item: edges){
            int u=item[0];
            int v=item[1];
            int wt=item[2];
            if(distance[u] != INT_MAX && distance[u]+wt<distance[v]){
                distance[v]=distance[u]+wt;
            }
        }
    }
    //To check -ve cycle
    for(auto item:edges){
        int u=item[0];
        int v=item[1];
        int wt=item[2];
        if(distance[u] != INT_MAX && distance[u]+wt<distance[v]){
            return vector<int>(V, -1);
        }
    }
    return distance;
}

/*
Bellman ford Algorithm
-Initialize distance to all vertices as ∞ (INT_MAX), and distance to source as 0.
-Relax all edges (V - 1) times:
    For each edge (u, v, wt), if distance[u] + wt < distance[v], update distance[v] = distance[u] + wt
-After relaxing all edges,
    If distance[u] + wt < distance[v], then a negative weight cycle exists.
*/