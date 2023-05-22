#include <iostream>

using namespace std;

int binary(int arr[], int low, int high, int key)
{

    int mid = (low + high) / 2;

    if (low > high)

        return -1;

    else if (arr[mid] == key)

        return mid + 1;

    else if (arr[mid] > key)

        return binary(arr, low, mid - 1, key);

    else

        return binary(arr, mid + 1, high, key);
}

int main()
{

    int size;

    cout << "Enter the size of the array : ";

    cin >> size;

    int arr[size];

    cout << "Enter the elements of the array : ";

    for (int i = 0; i < size; i++)
    {

        cin >> arr[i];
    }

    int key;

    cout << "Enter the key element : ";

    cin >> key;

    int index = binary(arr, 0, size - 1, key);

    if (index != -1)
    {

        cout << "Item found at " << index << endl;
    }

    else
    {

        cout << "Item not found" << endl;
    }

    return 0;
}