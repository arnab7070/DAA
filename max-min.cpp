#include <iostream>
using namespace std;
// finding max and min value from an array by using divide and conquer approach
void maxmin(int arr[], int start, int end, int &max, int &min)
{
    // single element or base case
    if (start == end)
    {
        max = min = arr[start];
        return;
    }
    // smaller subproblem
    if (start == end - 1)
    {
        if (arr[start] > arr[end])
        {
            max = arr[start];
            min = arr[end];
        }
        else
        {
            max = arr[end];
            min = arr[start];
        }
    }
    // recursive algorithm to solve the whole problem
    int mid = (start + end) / 2;
    int max_left, min_left, max_right, min_right;
    maxmin(arr, 0, mid, max_left, min_left);         // call for left recursion tree
    maxmin(arr, mid + 1, end, max_right, min_right); // call for right recursion tree
    max = max_right > max_left ? max_right : max_left;
    min = min_right < min_left ? min_right : min_left;
}

int main()
{
    int arr[] = {3, 1, 8, 9, 6, 8, 9, 5, 10, 15};
    int n = sizeof(arr) / sizeof(int);
    int max = -9999999, min = 9999999;
    maxmin(arr, 0, n - 1, max, min);
    cout << "MAX: " << max << "\nMIN: " << min << endl;
    return 0;
}