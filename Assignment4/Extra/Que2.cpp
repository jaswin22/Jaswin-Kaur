#include <iostream>
using namespace std;

#define MAX 100

class Queue
{
    int arr[MAX];
    int front, rear;
public:
    Queue()
    {
        front = rear = -1;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return (rear + 1) % MAX == front;
    }
    void enqueue(int x)
    {
        if (isFull())
            return;
        if (isEmpty())
            front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = x;
    }
    int dequeue()
    {
        if (isEmpty())
            return -1;
        int x = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
        return x;
    }
    int size()
    {
        if (isEmpty())
            return 0;
        if (rear >= front)
            return rear - front + 1;
        return MAX - front + rear + 1;
    }
    int frontElement()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }
    void sortQueue()
    {
        int n = size();
        for (int i = 1; i <= n; i++)
        {
            int minIndex = -1;
            int minValue = 1e9;
            int sz = size();
            for (int j = 0; j < sz; j++)
            {
                int curr = dequeue();
                if (curr <= minValue && j < sz - i + 1)
                {
                    minValue = curr;
                    minIndex = j;
                }
                enqueue(curr);
            }
            for (int j = 0; j < sz; j++)
            {
                int curr = dequeue();
                if (j == minIndex)
                    continue;
                enqueue(curr);
            }
            enqueue(minValue);
        }
    }
    void print()
    {
        int sz = size();
        for (int i = 0; i < sz; i++)
        {
            int x = dequeue();
            cout << x << " ";
            enqueue(x);
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(11);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(21);
    q.sortQueue();
    q.print();
    return 0;
}
