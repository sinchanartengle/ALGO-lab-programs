/*
b. Compute the transitive closure of a given directed graph using Warshall’s algorithm
*/

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
void fun(vector<vector<int>>& mat);

int main(){
    int V=4;
    vector<vector<int>> graph = 
    {{0, 1, 1, 0}, {0, 0, 1, 0}, {1, 0, 0, 1}, {0, 0, 0, 0}};
    fun(graph);
    for (int i=0; i<V; i++) {
      for (int j=0; j<V; j++) {
        cout << graph[i][j] << " ";
      }
      cout << endl;
    }
    return 0;
}

void fun(vector<vector<int>>& mat){
    int n=mat.size();
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (mat[i][k] == 1 && mat[k][j] == 1)
                    mat[i][j]=1;
            }
        }
    }
}

/*
--------------Algotithm----------------
Algorithm:
1)Initialization:
For vertices i and j:
    If there is a direct edge from i to j, mat[i][j] = 1
    If no edge exists, mat[i][j] = 0
2)For each intermediate vertex k from 0 to V - 1:
    For each source vertex i from 0 to V - 1:
        For each destination vertex j from 0 to V - 1:
            If mat[i][k] = 1 and mat[k][j] =1,
                mat[i][j] = 1

3)Print the mat.If mat[i][j] = 1, then there is a path from i to j.

Time Complexity: O(V^3)
Auxiliary Space: O(V^2)
*/