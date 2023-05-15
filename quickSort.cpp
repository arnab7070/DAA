#include <iostream>
#include <time.h>
using namespace std;
#define n 10
void print(int arr[])
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int partion(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    i++;
    swap(arr[high], arr[i]);
    return i;
}
// randomized quick sort
int randomPartition(int arr[], int low, int high)
{
    srand(time(NULL));
    int randomIndex = low + rand() % (high - low);
    swap(arr[randomIndex], arr[high]);
    return partion(arr, low, high);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = randomPartition(arr, low, high);
        quickSort(arr, 0, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int arr[n] = {8, 1, 3, 7, 2, 9, 5, 6, 4, 10};
    quickSort(arr, 0, 9);
    print(arr);
    return 0;
}