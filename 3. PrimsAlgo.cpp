/*
12. Find Minimum Cost Spanning Tree of a given undirected graph using Prim’s algorithm 
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int function(int v,vector<pair<int,int>> adj[]);

int main(){
    
    int V = 4;
    // Edge list: each sub-vector contains {u, v, weight}
    vector<vector<int>> edges = {
        {0, 1, 10},
        {1, 3, 15},
        {2, 3, 4},
        {2, 0, 6},
        {0, 3, 5}
    };
    vector<pair<int, int>> adj[V];
    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1], wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});  // because the graph is undirected
    }
    int mstCost = function(V, adj);
    cout << "Minimum Spanning Tree Cost: " << mstCost << endl;

    return 0;
}

int function(int v,vector<pair<int,int>> adj[]){
    //Min-heap priority queue where each element is a pair {weight, node}
    //greater<pair<int,int>> ensures the pair with the smallest weight is at the top
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //To keep track of visited nodes.
    vector<bool> isVisited(v,false);
    //Initial cost of MST is zero.
    int sum=0;

    pq.push({0,0});

    while(!pq.empty()){
        auto item=pq.top();
        pq.pop();
        int wt=item.first;
        int node=item.second;
        if(!isVisited[node]){
            isVisited[node]=true;
            sum+=wt;
            for(auto it: adj[node]){
                int adjWt=it.second;
                int adjNode=it.first;
                if(!isVisited[adjNode]){
                    pq.push({adjWt,adjNode});
                }
            }
        }
    }
    return sum;
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