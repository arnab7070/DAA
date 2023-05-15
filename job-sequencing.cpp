#include <iostream>
#include "myutility.cpp"
using namespace std;
int profit[] = {3, 5, 20, 18, 1, 6, 30};
int deadline[] = {1, 3, 4, 3, 2, 1, 2};
int size = 7;
// Structure JOB is defined in my utility file
void readInput(JOB *arr)
{
    for (int i = 0; i < size; i++)
    {
        arr[i].profit = profit[i];
        arr[i].deadline = deadline[i];
    }
}

void jobSequencing(JOB *arr)
{
    int ganntChartSize = getMax(deadline, size);
    int gannt_chart[ganntChartSize] = {0};
    for (int i = 0; i < size; i++)
    {
        int position = arr[i].deadline - 1;
        while (gannt_chart[position] > 0 && position > 0)
        {
            position--;
        }
        if (gannt_chart[position] == 0)
        {
            gannt_chart[position] = arr[i].profit;
        }
    }
    // calculate total profit
    int total_profit = 0;
    for (int i = 0; i < ganntChartSize; i++)
    {
        total_profit += gannt_chart[i];
    }
    cout << "Total profit can be earned: " << total_profit << endl;
}
int main()
{
    struct JOB arr[size];
    readInput(arr);
    JOBSort(arr, size);
    jobSequencing(arr);
    return 0;
}