#include <iostream>
#include <fstream>
using namespace std;
int n = 0; // number of vertex
struct Edge
{
    int a;
    int b;
    int weight;
};

Edge edgeArray[100];
int edgeCount = 0;

void readGraph()
{
    fstream input;
    input.open("graph.txt", ios::in);
    input >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int edgeWeight;
            input >> edgeWeight;
            if (edgeWeight > 0)
            {
                edgeArray[edgeCount].a = i;
                edgeArray[edgeCount].b = j;
                edgeArray[edgeCount++].weight = edgeWeight;
            }
        }
    }
    input.close();
}

void bubbleSort()
{
    for (int i = 0; i < edgeCount - 1; i++)
    {
        for (int j = 0; j < edgeCount - i - 1; j++)
        {
            if (edgeArray[j].weight > edgeArray[j + 1].weight)
            {
                swap(edgeArray[j], edgeArray[j + 1]);
            }
        }
    }
}

int parent[10];
Edge mst[100];
int mstEdge = 0;

void makeSet()
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
    }
}

int find(int i)
{
    while (parent[i] > 0)
    {
        i = parent[i];
    }
    return i;
}

void Union(int u, int v)
{
    int x = find(u);
    int y = find(v);
    parent[x] = y;
}

void kruskalAlgorithm()
{
    bubbleSort();
    makeSet();
    for (int i = 0; i < edgeCount; i++)
    {
        if (find(edgeArray[i].a) != find(edgeArray[i].b))
        {
            Union(edgeArray[i].a, edgeArray[i].b);
            mst[mstEdge].a = edgeArray[i].a;
            mst[mstEdge].b = edgeArray[i].b;
            mst[mstEdge++].weight = edgeArray[i].weight;
        }
    }
}

void printMST()
{
    int totalCost = 0;
    for (int i = 0; i < mstEdge; i++)
    {
        cout << "(" << char('A' + mst[i].a) << "," << char('A' + mst[i].b) << ")"
             << " -> " << mst[i].weight << endl;
        totalCost += mst[i].weight;
    }
    cout << "So, minimum edge weight for the spanning tree will be: " << totalCost << endl;
}

int main()
{
    readGraph();
    kruskalAlgorithm();
    printMST();
    return 0;
}