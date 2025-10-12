#include <iostream>
using namespace std;

class Stack
{
    int arr[50];
    int top;
    public:
        Stack() 
        { top = -1; }
        void push(int x);
        void pop();
        void isEmpty();
        void isFull();
        void display();
        void peek();
        void reverseString(string a);
};

void Stack::push(int x)
{
    if (top >= 49)
        cout << "Stack Overflow\n";
    else
        arr[++top] = x;
}

void Stack::pop()
{
    top < 0 ?   cout << "Stack Underflow\n" : cout << "Popped: " << arr[top--] << endl;
}
void Stack::isEmpty()
{
    top < 0 ?   cout << "Stack is empty\n"  : cout << "Stack is not empty\n";
}
void Stack::isFull()
{
    top >= 49 ? cout << "Stack is full\n"   : cout << "Stack is not full\n";
}
void Stack::peek()
{
    top < 0 ?   cout << "Stack is empty\n"  : cout << "Top element: " << arr[top] << endl;
}

void Stack::display()
{
    if (top < 0)
        cout << "Stack is empty\n";
    else
    {
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    
}

void Stack::reverseString(string a)
{
    int len = a.length();
    Stack s;

    for (int i = 0; i < len; i++)
        s.push(a[i]);
    cout << "Reversed string: ";

    for (int i = 0; i < len; i++)
        cout << (char)s.arr[s.top--];
    cout << endl;
}

int main()
{
    Stack s;
    string str;
    int choice = 0, value;
    do {
        cout << "\nMenu:\n" << "1. Push\n" << "2. Pop\n" << "3. isEmpty\n" << "4. isFull\n" << "5. Display\n" << "6. Peek\n" << "7. Reverse String\n" << "8. Exit\n" << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1: cout << "Enter value to push: ";    cin >> value;   s.push(value);   break;
            case 2:     s.pop();        break;
            case 3:     s.isEmpty();    break;
            case 4:     s.isFull();     break;
            case 5:     s.display();    break;
            case 6:     s.peek();       break;
            case 7: cout << "Enter string to reverse: ";    cin >> str; s.reverseString(str);    break;
            case 8:     cout << "Exiting...\n"; break;
            default:    cout << "Invalid choice!\n";
        }
    } while (choice != 8);
    return 0;
}