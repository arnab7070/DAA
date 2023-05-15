#include <iostream>
#include "myutility.cpp"
using namespace std;
void DFS_Recursion(int i, int *visited)
{
    visited[i] = 1; // mark as visited
    cout << char('A' + i) << " ";
    for (int j = 0; j < n; j++)
    {
        if (adjMat[i][j] == 1 && !visited[j])
        {
            DFS_Recursion(j, visited); // call for next iteration
        }
    }
}
int main()
{
    readGraph();
    int visited[n] = {0};
    DFS_Recursion(0, visited);
    return 0;
}