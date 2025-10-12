#include <iostream>
using namespace std;

class Stack
{
    int arr[100], top, minEle;
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
        if (isEmpty())
        {
            top++;
            arr[top] = x;
            minEle = x;
        }
        else if (x < minEle)
        {
            arr[++top] = 2 * x - minEle;
            minEle = x;
        }
        else
        {
            arr[++top] = x;
        }
    }
    void pop()
    {
        if (isEmpty())
            return;
        int t = arr[top--];
        if (t < minEle)
            minEle = 2 * minEle - t;
    }
    int getMin()
    {
        return isEmpty() ? -1 : minEle;
    }
    int view()
    {
        if (isEmpty())
            return -1;
        int t = arr[top];
        return t < minEle ? minEle : t;
    }
};

int main()
{
    Stack s;
    s.push(3);
    s.push(5);
    cout << s.getMin() << endl;
    s.push(2);
    s.push(1);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << s.view() << endl;
    return 0;
}
