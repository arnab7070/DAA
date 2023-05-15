#include <iostream>
#include <climits>
using namespace std;
int front = -1;
int rear = -1;
int queue[100] = {0};

void push(int element)
{
    if (front == -1)
        front++;
    queue[++rear] = element;
}
void pop()
{
    front++;
}
bool isEmpty()
{
    return front > rear;
}
int peek()
{
    return queue[front];
}