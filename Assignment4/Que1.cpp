// 1) Develop a menu driven program demonstrating the following operations on simple Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().

#include<iostream>
using namespace std;

class Queue
{
    int arr[100], front, rear, size;
    public:
        Queue(int size);
        void enqueue(int x);
        void dequeue();
        bool isEmpty();
        bool isFull();
        void display();
        void peek();
};

Queue::Queue(int size)
{
    size = size;
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
        front = 0;
    arr[++rear] = x;
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
    front == rear ? front = rear = -1 : front++;
}

bool Queue::isEmpty()
{
    return front == -1;
}

bool Queue::isFull()
{
    return rear == size - 1;
}

void Queue::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return;
    }
    for (int i = front; i <= rear; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Queue::peek()
{
    isEmpty() ? cout << "Queue is empty\n" : cout << "Front: " << arr[front] << endl;
}

int main()
{
    int size, choice, val;
    cout << "Enter queue size: ";
    cin >> size;
    Queue q(size);
    do {
        cout << "\t1.Enqueue \n\t2.Dequeue \n\t3.isEmpty \n\t4.isFull \n\t5.Display \n\t6.Peek \n\t7.Exit\n" << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1: cout << "Enter value: ";    cin >> val;     q.enqueue(val);             break;
            case 2: q.dequeue();    break;
            case 3: cout << (q.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");    break;
            case 4: cout << (q.isFull()  ? "Queue is full\n"  : "Queue is not full\n" );    break;
            case 5: q.display();    break;
            case 6: q.peek();       break;
            case 7: break;
            default : cout << "Invalid Choice";  
        }
    } while (choice != 7);
}