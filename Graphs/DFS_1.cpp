#include <iostream>
using namespace std;

/*  In depth first search, once we start down a path, we don't stop until we got to the end.
    In other words, we traverse through one branch of a tree until we get to a leaf, and then we 
    work our way back to the trunk of the tree.
          STEPS
    # Create a recursive function that takes the index of the node and a visited array.
    # Mark the current node as visited and print the node.
    # Traverse all the adjacent and unmarked nodes and call the recursive function with the index of the adjacent node.
*/
void DFS(int arr[][7], int v, int n)
{
    static int visited[7] = {0};
    // check if the vertex is visited or not
    //  if not visited visit it
    if (visited[v] == 0)
    {
        cout << v << "  ";
        visited[v] = 1;     // mark the visited vertex as 1;
        //  explore the visited vertex
        for (int j = 0; j < n; j++)
        {
            if (arr[v][j] == 1 && visited[j]==0)     //  suspend the vertex and explore its adjacent vertex
                DFS(arr, j, n);
        }
    }
}

int main()
{
    int A[7][7] = {{0, 1, 0, 1, 0, 0, 0},
                   {1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 0, 1, 1, 0, 0},
                   {1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    cout << "Vertex: 2 -> ";
    DFS(A, 2, 7);

    //cout << "Vertex: 4 -> ";
    //DFS(A, 4, 7);
    return 0;
}