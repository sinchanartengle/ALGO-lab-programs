/*
A Multistage graph is a directed, weighted graph in which the nodes can be divided into a set of stages 
such that all edges are from a stage to next stage only (In other words there is no edge between vertices 
of same stage and from a vertex of current stage to previous stage).
https://www.geeksforgeeks.org/multistage-graph-shortest-path/
*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

#define INF INT_MAX
int shortestDistance(vector<vector<int>> graph);

int main(){

    vector<vector<int>> graph={
        {{INF, 1, 2, 5, INF, INF, INF, INF},
       {INF, INF, INF, INF, 4, 11, INF, INF},
       {INF, INF, INF, INF, 9, 5, 16, INF},
       {INF, INF, INF, INF, INF, INF, 2, INF},
       {INF, INF, INF, INF, INF, INF, INF, 18},
       {INF, INF, INF, INF, INF, INF, INF, 13},
       {INF, INF, INF, INF, INF, INF, INF, 2},
      {INF, INF, INF, INF, INF, INF, INF, INF}}
    };
    cout << shortestDistance(graph);
    return 0;
}

int shortestDistance(vector<vector<int>> graph){
    int n=graph.size();
    // dist[i] is going to store shortest
    // distance from node i to node N-1.
    vector<int> distance(n);
    // Calculating shortest path for
    // rest of the nodes
    for(int i=n-2;i>=0;i--){
        // Initialize distance from i to
        // destination (N-1)
        distance[i]=INF;
        // Check all nodes of next stages
        // to find shortest distance from
        // i to N-1.
        for(int j=i;j<n;j++){
            // Reject if no edge exists
            if (graph[i][j] == INF)
                continue;
            // We apply equation to
            // distance to target through j.
            // and compare with minimum distance 
            // so far.
            distance[i] = min(distance[i],graph[i][j]+distance[j]);
        }
    }
    return distance[0];
}

/*
1)Initialize:
    Create an  distance[ array to store the shortest distance from each node to the destination.
    Set distance[n−1] = 0 (since the distance from destination to itself is zero).
2)Compute shortest distances in reverse (from n−2 to 0):
    For i from n−2 down to 0:
        Set distance[i] = ∞
        For j from i to n:
            If there is an edge from i to j (i.e., graph[i][j] ≠ ∞):
                Update distance[i] = min(distance[i], graph[i][j] + distance[j])
3)Return distance[0] as the result.

Time Complexity: O(N^2)
Space Complexity: O(N)
*/