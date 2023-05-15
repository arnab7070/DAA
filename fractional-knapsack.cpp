#include <iostream>
#include "myutility.cpp"
using namespace std;
int size = 7;
int weight = 15;
int Profit[] = {10, 5, 15, 7, 6, 18, 3};
int Weight[] = {2, 3, 5, 7, 1, 4, 1};
// KnapSack structure is defined in myutility.cpp
void readInput(KnapSack *arr)
{
    for (int i = 0; i < size; i++)
    {
        arr[i].profit = Profit[i];
        arr[i].weight = Weight[i];
        arr[i].ratio = (double)Profit[i] / Weight[i];
    }
}

void fractional_Knapsack(KnapSack *arr)
{
    double profit = 0;
    for (int i = 0; i < size; i++)
    {
        if (weight == 0)
        {
            break;
        }
        int weight_taken = min(weight, arr[i].weight);
        profit += weight_taken * arr[i].ratio;
        weight -= weight_taken;
    }
    printf("Total profit can be earned: %.2f\n", profit);
}

int main()
{
    struct KnapSack arr[size];
    readInput(arr);
    KnapSackSort(arr, size);
    fractional_Knapsack(arr);
    return 0;
}