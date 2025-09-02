/*
7)b. Check whether a given graph is connected or not using DFS method.   
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void dfs(int V,vector<bool>& isVisited,vector<vector<int>>& adjList);

int main(){
    vector<vector<int>> adjList = {{1,2}, {0,2,3}, {0,4}, {1,4}, {2,3}};
    // vector<vector<int>> adjList = {{1},{0},{}};
     
    //Retrieving total number of vertices
    int V=adjList.size();
    vector<bool> isVisited(V,false);
    //To count the number of subgraphs
    int count=0; 
    for(int node=0;node<V;node++){
        if(!isVisited[node]){
            dfs(node,isVisited,adjList);
            count++;
        }
    }
    count==1 ? cout<< "\nGiven graph is connected." : cout<<"\nGiven graph is disconnected.";
    return 0;
}


void dfs(int node,vector<bool>& isVisited,vector<vector<int>>& adjList){
    isVisited[node]=true;
    for(int item:adjList[node]){
        if(!isVisited[item]){
            dfs(item,isVisited,adjList);
        }
    }
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
