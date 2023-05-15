#include <iostream>
using namespace std;
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void merge(int arr[], int low, int mid, int high)
{
    int len1 = mid - low + 1;
    int len2 = high - mid;
    int arr1[len1], arr2[len2];
    int mainArrayIndex = low;
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[mainArrayIndex++]; // fill array 1
    }
    for (int i = 0; i < len1; i++)
    {
        arr2[i] = arr[mainArrayIndex++]; // fill array 2
    }
    mainArrayIndex = low;
    int index1 = 0, index2 = 0;
    while (index1 < len1 && index2 < len2)
    {
        if (arr1[index1] < arr2[index2])
        {
            arr[mainArrayIndex++] = arr1[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = arr2[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = arr1[index1++];
    }
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = arr2[index2++];
    }
}
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
void readInput(int &n, int arr[])
{

    cout << "Now enter the values in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    readInput(n, arr);
    mergeSort(arr, 0, n);
    print(arr, n);
    return 0;
}