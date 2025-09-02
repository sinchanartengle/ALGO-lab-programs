#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
void fun(vector<vector<int>>& mat);
const int INF = INT_MAX; 

int main(){
    int V=4;
    vector<vector<int>> graph = {
        {0,5,INF,10},
        {INF, 0,3,INF},
        {INF, INF, 0,1},
        {INF, INF, INF, 0}
    };
    fun(graph);
    for (int i=0;i<V;i++) {
        for (int j=0;j<V;j++) {
            if (graph[i][j]==INF)
                cout << "INF\t";
            else
                cout << graph[i][j] << "\t";
        }
        cout<<endl;
    }
    return 0;
}

void fun(vector<vector<int>>& mat){
    int n=mat.size();
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (mat[i][k] != INF && mat[k][j] != INF)
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }
}

/*
--------------Algotithm----------------
Algorithm:
1)Initialization:
For vertices i and j:
    If i == j, then mat[i][j] = 0
    If there is a direct edge from i to j, mat[i][j] = weight
    If no edge exists, mat[i][j] = INF
2)For each intermediate vertex k from 0 to V - 1:
    For each source vertex i from 0 to V - 1:
        For each destination vertex j from 0 to V - 1:
            If mat[i][k] != INF and mat[k][j] != INF,
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j])

3)Print the mat.If mat[i][j] == INF, then there is no path from i to j.

Time Complexity: O(V^3)
Auxiliary Space: O(1)
*/