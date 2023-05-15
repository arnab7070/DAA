#include <iostream>
#include "myutility.cpp"
#include "queue.cpp"
using namespace std;
void BFS(int i, int *visited)
{
    cout << char('A' + i) << " ";
    visited[i] = 1; // mark as visited
    push(i);
    while (!isEmpty())
    {
        int node = peek();
        pop();
        for (int j = 0; j < n; j++)
        {
            if (adjMat[node][j] == 1 && !visited[j])
            {
                visited[j] = 1;
                push(j);
                cout << char('A' + j) << " ";
            }
        }
    }
}
int main()
{
    readGraph();
    int visited[n] = {0};
    BFS(0, visited);
    return 0;
}