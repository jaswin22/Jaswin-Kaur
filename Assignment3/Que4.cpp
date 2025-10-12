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

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isAlphaNum(char c) 
{
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool isSpace(char c) 
{
    return c == ' ' || c == '\t' || c == '\n';
}

void infixToPostfix(const char* infix, char* postfix) 
{
    Stack st;
    int j = 0;
    for (int i = 0; infix[i] != '\0'; ++i) 
    {
        char c = infix[i];
        if (isSpace(c))
            continue;
        else if (isAlphaNum(c))
            postfix[j++] = c;
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (!st.empty() && st.peek() != '(') 
            {
                postfix[j++] = st.peek();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        } 
        else if (isOperator(c)) {
            while (!st.empty() && precedence(st.peek()) >= precedence(c)) 
            {
                if (c == '^' && st.peek() == '^') 
                    break;
                postfix[j++] = st.peek();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) 
    {
        postfix[j++] = st.peek();
        st.pop();
    }
    postfix[j] = '\0';
}

int main() 
{
    char infix[50], postfix[50];
    cout << "Enter infix expression: ";
    cin.getline(infix, 50);

    infixToPostfix(infix, postfix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
