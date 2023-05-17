#include <iostream>
#include <fstream>
using namespace std;

struct Edge
{
    int a;
    int b;
    int weight;
};
int n; // number of vertices
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

int adjMatrix[100][100];

void readGraph()
{
    fstream input;
    input.open("graph.txt", ios::in);
    input >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            input >> adjMatrix[i][j];
        }
    }
    input.close();
}

void primMST()
{
    Priority_Queue pq;
    int mstWeight = 0;
    bool visited[n] = {false};
    pq.insert(0, 0, 0);
    while (pq.size > 0)
    {
        Edge curr = pq.extractMin();
        if (!visited[curr.b])
        {
            visited[curr.b] = true;
            for (int i = 0; i < n; i++)
            {
                int edgeWeight = adjMatrix[curr.b][i];
                if (edgeWeight > 0 && !visited[i])
                {
                    pq.insert(curr.b, i, edgeWeight);
                }
            }
            mstWeight += curr.weight;
            if (curr.a != curr.b)
                cout << "Edge: " << char('A' + curr.a) << "-" << char('A' + curr.b) << " Weight: " << curr.weight << endl;
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