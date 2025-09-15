/*
b. Compute the transitive closure of a given directed graph using Warshall’s algorithm
*/

#include <iostream>
using namespace std;
#define MAX 10

int i,j,k,cost[MAX][MAX];

void createGraph(int cost[MAX][MAX], int n){
    cout << "Enter cost Matrix: \n";
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            cin >> cost[i][j];
        }
    }
}

void warshall(int cost[MAX][MAX], int n){
    for (k = 0; k < n; k++){
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                cost[i][j] = cost[i][j] || (cost[i][k] && cost[k][j]);
            }
        }
    }
}
/*
void warshall(int adj[MAX][MAX], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                adj[j][k] = adj[j][k] || (adj[j][i] && adj[i][k]);
            }
        }
    }
}
*/

void printGraph(int cost[MAX][MAX], int n){
    cout << "After Applying Warshall's Transitive Closure:\n";
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            cout << cost[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    int n;
    cout << "Enter No of Vertices: ";
    cin >> n;
    createGraph(cost, n);
    warshall(cost, n);
    printGraph(cost, n);
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
