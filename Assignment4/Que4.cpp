// 4) Write a program to find first non-repeating character in a string using Queue. Sample I/P: a a b c Sample O/P: a -1 b b

#include<iostream>
using namespace std;

class Queue
{
    int arr[100], front, rear, size;
public:
    Queue(int s);
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    bool isFull();
    int peek();
    void findFirstNonRepeating(char* str);
};

Queue::Queue(int s)
{
    size = s;
    front = rear = -1;
}

void Queue::enqueue(int x)
{
    if (isFull())
        return;
    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % size;
    arr[rear] = x;
}

int Queue::dequeue()
{
    if (isEmpty())
        return -1;
    int val = arr[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % size;
    return val;
}

bool Queue::isEmpty()
{
    return front == -1;
}

bool Queue::isFull()
{
    return ((rear + 1) % size == front);
}

int Queue::peek()
{
    if (isEmpty())
        return -1;
    return arr[front];
}

void Queue::findFirstNonRepeating(char* str)
{
    int freq[26] = {0};
    Queue q(100);

    for (int i = 0; str[i] != '\0'; ++i)
    {
        char ch = str[i];
        if (ch == ' ') continue;
        freq[ch - 'a']++;

        if (freq[ch - 'a'] == 1)
            q.enqueue(ch);

        while (!q.isEmpty() && freq[q.peek() - 'a'] > 1)
            q.dequeue();

        if (q.isEmpty())
            cout << "-1 ";
        else
            cout << (char)q.peek() << " ";
    }
    cout << endl;
}

int main()
{
    int s = 100;
    Queue q(s);

    char s1[] = "aabc";
    q.findFirstNonRepeating(s1);

    char s2[] = "a a b c";
    q.findFirstNonRepeating(s2);
}
