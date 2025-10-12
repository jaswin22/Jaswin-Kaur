// 3) Write a program interleave the first half of the queue with second half. Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9

#include<iostream>
using namespace std;

class Queue
{
    int arr[100], front, rear, size;
public:
    Queue(int s);
    void enqueue(int x);
    void dequeue();
    bool isEmpty();
    bool isFull();
    void display();
    void peek();
    void interleave();
};

Queue::Queue(int s)
{
    size = s;
    front = rear = -1;
}

void Queue::enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue is full\n";
        return;
    }
    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % size;
    arr[rear] = x;
    cout << "Enqueued: " << x << endl;
}

void Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Dequeued: " << arr[front] << endl;
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % size;
}

bool Queue::isEmpty()
{
    return front == -1;
}

bool Queue::isFull()
{
    return ((rear + 1) % size == front);
}

void Queue::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return;
    }
    int i = front;
    while (true)
    {
        cout << arr[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    cout << endl;
}

void Queue::peek()
{
    isEmpty() ? cout << "Queue is empty\n" : cout << "Front: " << arr[front] << endl;
}

void Queue::interleave()
{
    if (isEmpty()) { cout << "Queue is empty\n"; return; }
    int n = 0;
    if (front <= rear) {
        n = rear - front + 1;
    } else {
        n = size - front + rear + 1;
    }
    if (n % 2 != 0) { cout << "Queue size must be even to interleave\n"; return; }
    int half = n / 2, temp[100], idx = 0;
    int i = front;
    for (int count = 0; count < n; ++count) {
        temp[idx++] = arr[i];
        i = (i + 1) % size;
    }
    idx = front;
    for (int j = 0; j < half; ++j) {
        arr[idx] = temp[j];
        idx = (idx + 1) % size;
        arr[idx] = temp[j + half];
        idx = (idx + 1) % size;
    }
}

int main()
{
    int s, ch, val;
    cout << "Enter queue size (max 100): ";
    
    cin >> s;
    if (s > 100 || s <= 0) {
        cout << "Invalid size! Please enter a value between 1 and 100.\n";
        return 1;
    }
    Queue q(s);

    do {
        cout << "\t1.Enqueue \n\t2.Dequeue \n\t3.isEmpty \n\t4.isFull \n\t5.Display \n\t6.Peek \n\t7.Interleave \n\t8.Exit\n" << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: cout << (q.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n"); break;
            case 4: cout << (q.isFull() ? "Queue is full\n" : "Queue is not full\n" ); break;
            case 5: q.display(); break;
            case 6: q.peek(); break;
            case 7: q.interleave(); break;
            case 8: break;
            default : cout << "Invalid Choice\n";
        }
    } while (ch != 8);
}
