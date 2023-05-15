#include <iostream>
using namespace std;

void binarySearch(int arr[], int start, int end, int key)
{
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            cout << "Element found at index " << mid << endl;
            return;
        }
        // if key < arr[mid] that means element is at left side
        if (key < arr[mid])
            return binarySearch(arr, 0, mid, key);
        else
            return binarySearch(arr, mid + 1, end, key); // otherwise element is at right side
    }
    cout << "Element not found" << endl;
}

int main()
{
    int arr[] = {1, 4, 5, 6, 78, 89, 145, 669, 1489};
    int n = sizeof(arr) / sizeof(int);
    int key = 6;
    binarySearch(arr, 0, n, key);
    return 0;
}