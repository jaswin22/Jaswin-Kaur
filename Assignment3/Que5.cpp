#include <iostream>
using namespace std;

class Stack {
    char arr[50];
    int top;
public:
    Stack() : top(-1) {}
    bool empty()
    {
        return top == -1;
    }
    char peek()
    {
        return (top >= 0) ? arr[top] : '\0';
    }
    void push(char c)
    {
        if (top < 49) arr[++top] = c;
    }
    void pop()
    {
        if (top >= 0) --top;
    }
};

int applyOp(int a, int b, char op) {
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
        return a / b;
    if (op == '^')
        return a^b;
    return 0;
}

int main()
{
    Stack s;
    char expr[50];
    cout << "Enter postfix expression (single-digit operands, no spaces): ";
    cin >> expr;

    int vals[50], vtop = -1;

    for (int i = 0; expr[i] != '\0'; ++i)
    {
        char c = expr[i];
        if (c >= '0' && c <= '9')
            vals[++vtop] = c - '0';
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            int b = vals[vtop--], a = vals[vtop--];
            int res = applyOp(a, b, c);
            vals[++vtop] = res;
        }
    }
    cout << "Result: " << vals[vtop] << endl;
    return 0;
}
