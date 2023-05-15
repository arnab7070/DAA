#include <fstream>
using namespace std;
int adjMat[100][100]; // Global Array
int n;
void readGraph()
{
    fstream input;
    input.open("graph.txt", ios::in);
    input >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            input >> adjMat[i][j];
        }
    }
    input.close();
}
struct JOB
{
    int profit;
    int deadline;
};

void JOBSort(JOB *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j].profit < arr[j + 1].profit)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
template <typename T>
int getMax(T *arr, int n)
{
    int maxVal = 0;
    for (int i = 0; i < n; i++)
    {
        maxVal = max(arr[i], maxVal);
    }
    return maxVal;
}

struct KnapSack
{
    int profit;
    int weight;
    double ratio;
};

void KnapSackSort(KnapSack *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j].ratio < arr[j + 1].ratio)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}