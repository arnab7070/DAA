#include <iostream>
using namespace std;
#define INF 999
int w[4][4] = {0, 3, INF, 5,
               2, 0, INF, 4,
               INF, 1, 0, INF,
               INF, INF, 2, 0};

int n = 4;
int dist[10][10];
int pred[10][10];
void initialize()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = w[i][j];
            if (w[i][j] == 0 || w[i][j] == 999)
            {
                pred[i][j] == -1;
            }
            else
            {
                pred[i][j] = i;
            }
        }
    }
}
void Floyd()
{
    initialize();
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != 999 && dist[k][j] != 999)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        pred[i][j] = pred[k][j];
                    }
                }
            }
        }
    }
}
void APSP(int i, int j)
{
    if (i == j)
        cout << " " << i + 1;
    else if (pred[i][j] == -1)
        cout << "NO PATH" << endl;
    else
    {
        APSP(i, pred[i][j]);
        cout << " " << j + 1;
    }
}
int main()
{
    Floyd();
    APSP(0, 2);
    return 0;
}