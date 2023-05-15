#include <iostream>
#include <fstream>
using namespace std;

struct Edge
{
    int a;
    int b;
    int weight;
};

#define CAPACITY 100
class Priority_Queue
{
public:
    Edge arr[CAPACITY];
    int size = 0;
    void insert(int source, int dest, int weight)
    {
        size++;
        int index = size;
        arr[index].a = source;
        arr[index].b = dest;
        arr[index].weight = weight;
        int parent = index / 2;
        while (arr[parent].weight > arr[index].weight && index > 1)
        {
            swap(arr[parent], arr[index]);
            index = parent;
            parent = index / 2;
        }
    }

    Edge extractMin()
    {
        Edge min = arr[1];
        arr[1] = arr[size];
        size--;

        int index = 1;
        while (index <= size / 2)
        {
            int left_child = 2 * index;
            int right_child = 2 * index + 1;
            int smallest = index;

            if (left_child <= size && arr[left_child].weight < arr[smallest].weight)
            {
                smallest = left_child;
            }
            if (right_child <= size && arr[right_child].weight < arr[smallest].weight)
            {
                smallest = right_child;
            }
            if (smallest != index)
            {
                swap(arr[smallest], arr[index]);
                index = smallest;
            }
            else
            {
                break;
            }
        }

        return min;
    }
};

Edge edgeArray[100];
int edgeCount = 0;

void readGraph()
{
    fstream input;
    input.open("graph.txt", ios::in);
    int n;
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

void primMST()
{
    Priority_Queue pq;
    int mstWeight = 0;
    bool visited[100] = {false};
    visited[edgeArray[0].a] = true;

    for (int i = 0; i < edgeCount; i++)
    {
        if (edgeArray[i].a == edgeArray[0].a)
        {
            pq.insert(edgeArray[i].a, edgeArray[i].b, edgeArray[i].weight);
        }
    }

    while (pq.size > 0)
    {
        Edge minEdge = pq.extractMin();
        if (visited[minEdge.b])
        {
            continue;
        }
        visited[minEdge.b] = true;
        mstWeight += minEdge.weight;
        cout << "Edge: " << minEdge.a << "-" << minEdge.b << " Weight: " << minEdge.weight << endl;
        for (int i = 0; i < edgeCount; i++)
        {
            if (edgeArray[i].a == minEdge.b && !visited[edgeArray[i].b])
            {
                pq.insert(edgeArray[i].a, edgeArray[i].b, edgeArray[i].weight);
            }
        }
    }
    cout << "Total weight of MST: " << mstWeight << endl;
}

int main()
{
    readGraph();
    primMST();
    return 0;
}