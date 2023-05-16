#include <iostream>
#include <fstream>
#include <climits>
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

void dijkstraAlgorithm()
{
    Priority_Queue pq;
    bool visited[n] = {false};
    int distance[n];
    for (int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
    }
    distance[0] = 0; // starting point distance is always zero
    pq.insert(0, 0, 0);
    while (pq.size > 0)
    {
        Edge curr = pq.extractMin();
        if (visited[curr.b] == false)
        {
            visited[curr.b] = true;
            for (int i = 0; i < n; i++)
            {
                // if edge exists
                if (adjMatrix[curr.b][i])
                {
                    int edgeWeight = adjMatrix[curr.b][i];
                    int source = curr.b;
                    int destination = i;
                    // relaxation
                    if (distance[source] + edgeWeight < distance[destination])
                    {
                        distance[destination] = distance[source] + edgeWeight;
                        pq.insert(source, destination, edgeWeight);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "(" << char('A' + 0) << "-" << char('A' + i) << ") -> " << distance[i] << endl;
    }
}

int main()
{
    readGraph();
    dijkstraAlgorithm();
    return 0;
}