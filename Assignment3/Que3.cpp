#include <iostream>
using namespace std;

class Stack {
    char arr[50];
    int top;
public:
    Stack() : top(-1) {}
        void push(char c) 
        { 
            arr[++top] = c; 
        }
        void pop() 
        { 
            if (top >= 0) --top;
        }
        char peek() 
        { 
            if (top >= 0)
                return arr[top];
            return '\0';
        }
        bool empty() 
        { 
            return top == -1; 
        }
};

bool isBalanced(const string& expr) {
    Stack s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') 
            s.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') 
        {
            if (s.empty())
                return false;

            char top = s.peek();

            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '['))
                return false;
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;
    if (isBalanced(expr))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
    return 0;
}