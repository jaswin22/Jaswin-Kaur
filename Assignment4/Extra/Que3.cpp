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
    void enqueue(int x)
    {
        rear == MAX - 1 ? void() : (isEmpty() ? front = 0 : void()), rear == MAX - 1 ? void() : arr[++rear] = x;
    }
    int dequeue()
    {
        return isEmpty() ? -1 : (front == rear ? (front = rear = -1, arr[front + 1]) : arr[front++]);
    }
    int frontElement()
    {
        return isEmpty() ? -1 : arr[front];
    }
    int size()
    {
        return isEmpty() ? 0 : rear - front + 1;
    }
};

class Stack
{
    int arr[MAX];
    int top;
public:
    Stack()
    {
        top = -1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    void push(int x)
    {
        top == MAX - 1 ? void() : arr[++top] = x;
    }
    int pop()
    {
        return isEmpty() ? -1 : arr[top--];
    }
    int peek()
    {
        return isEmpty() ? -1 : arr[top];
    }
};

bool checkSorted(Queue &q)
{
    Stack st;
    int expected = 1, n = q.size();
    while (!q.isEmpty())
    {
        int front = q.dequeue();
        front == expected ? expected++ : (!st.isEmpty() && st.peek() == expected ? (st.pop(), expected++) : (!st.isEmpty() && st.peek() < front ? (expected = -1) : st.push(front)));
        if (expected == -1)
            break;
    }
    while (!st.isEmpty() && st.peek() == expected)
    {
        st.pop();
        expected++;
    }
    return expected - 1 == n;
}

int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << (checkSorted(q) ? "Yes" : "No") << endl;
    return 0;
}
