#include <iostream>
using namespace std;
#define INT_MAX 2147483647
int arr[] = {2, 3, 5, 2, 4};
int dp[10][10] = {0};
int parenthesis[10][10] = {0};
int n = sizeof(arr) / sizeof(int) - 1;

void printArray()
{
    cout << "Cost Array" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%3d", dp[i][j]);
        }
        cout << endl;
    }
    cout << "Parenthesis Array" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%3d", parenthesis[i][j]);
        }
        cout << endl;
    }
}

void showParenthesis(int i, int j)
{
    if (i == j)
    {
        cout << char('A' + i);
    }
    else
    {
        cout << "(";
        showParenthesis(i, parenthesis[i][j]);
        showParenthesis(parenthesis[i][j] + 1, j);
        cout << ")";
    }
}

void matrixChainOrder()
{
    for (int len = 2; len <= n; len++)
    {
        for (int row = 1; row <= n - len + 1; row++)
        {
            int col = row + len - 1;
            dp[row][col] = INT_MAX;
            for (int k = row; k <= col - 1; k++)
            {
                int cost = dp[row][k] + dp[k + 1][col] + (arr[row - 1] * arr[k] * arr[col]);
                if (cost < dp[row][col])
                {
                    dp[row][col] = cost;
                    parenthesis[row][col] = k;
                }
            }
        }
    }
    printArray();
    cout << "Minimum operations required is: " << dp[1][n] << endl;
    showParenthesis(0, n);
}

int main()
{
    matrixChainOrder();
    return 0;
}