#include <iostream>
using namespace std;

void ternarySearch(int arr[], int start, int end, int key)
{
    while (start < end)
    {
        int mid1 = start + (end - start) / 3; // mid = initialization point (+/-) total_distance/3
        int mid2 = end - (end - start) / 3;
        if (arr[mid1] == key || arr[mid2] == key)
        {
            cout << "Element Found!!!" << endl;
            return;
        }
        if (key < arr[mid1])
            return ternarySearch(arr, start, mid1, key);
        else if (key > arr[mid1] && key < arr[mid2])
            return ternarySearch(arr, mid1 + 1, mid2, key);
        else
            return ternarySearch(arr, mid2 + 1, end, key);
    }
    cout << "Element Not Found" << endl;
}
int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "Enter the value of key: ";
    cin >> key;
    ternarySearch(arr, 0, n, key);
    return 0;
}