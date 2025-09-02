/*
11. Find Minimum Cost Spanning Tree of a given undirected graph using Kruskal’s algorithm. 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int spanningTree(int v,vector<vector<int>> adj);

// Disjoint Set Union (DSU)
class DisjointSet{
    vector<int> rank,parent;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1,0);
            for(int i=0;i<=n;i++){
                // Initially each node is its own parent
                parent[i]=i;
            }
        }
        //Returns the ultimate parent
        int findUPar(int node){
            if(node==parent[node])
                return node;
            return parent[node]=findUPar(parent[node]);
        }
        void unionByRank(int u,int v){
            // Ultimate parent of u
            int ultp_u=findUPar(u);
            // Ultimate parent of v
            int ultp_v=findUPar(v);
            if(ultp_u==ultp_v)return;
            if(rank[ultp_u]<rank[ultp_v]){
                parent[ultp_u]=ultp_v;

            }
            else if(rank[ultp_v]<rank[ultp_u]){
                parent[ultp_v]=ultp_u;
            }
            else{
                parent[ultp_v]=ultp_u;
                rank[ultp_u]++;
            }
            
        }
};

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

    int mstCost = spanningTree(V, edges);
    cout << "Minimum Spanning Tree Cost: " << mstCost << endl;
    return 0;
}

int spanningTree(int v,vector<vector<int>> adj){
    DisjointSet ds(v);
    vector<pair<int,pair<int,int>>> edges;
    int minStWt=0;

    // Convert edge list to a vector of tuples: {weight, {u, v}}
    for(auto item : adj){
            int u=item[0];
            int v=item[1];
            int wt=item[2];
            edges.push_back({wt,{u,v}});
    }

    // Step 1: Sort edges by weight
    sort(edges.begin(),edges.end());// O(E*logE)

    // Step 2 & 3: Pick smallest edge, include if no cycle is formed
    //O(logV)
    for(auto edge: edges){
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        // Check if u and v are in different sets (no cycle)
        if(ds.findUPar(u) != ds.findUPar(v)){
            minStWt+=wt;
            ds.unionByRank(u,v);
        }
    }
    return minStWt;
}

/*
Time Complexity:O(E * logE)-where V is the number of vertices and E is the number of edges in the graph.
Auxiliary Space: O(E+V)-where V is the number of vertices and E is the number of edges in the graph.

-------------------------Algorithm for Kruskals Algorithm---------------------
1)Sort all the edges in a non-decreasing order of their weight. 
2)Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. 
    If the cycle is not formed, include this edge. Else, discard it. 
3)Repeat step 2 until there are (V-1) edges in the spanning tree.

*/