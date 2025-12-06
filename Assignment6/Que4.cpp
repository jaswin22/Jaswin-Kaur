#include <iostream>
using namespace std;

struct Node
{
    char val;
    Node *prev, *next;
};

Node* add_last(Node* h, char x)
{
    Node* t = new Node;
    t->val = x;
    t->next = nullptr;
    if(!h)
    {
        t->prev = nullptr;
        return t;
    }
    Node* c = h;
    while(c->next)
    {
        c = c->next;
    }
    c->next = t;
    t->prev = c;
    return h;
}

bool is_pal(Node* h)
{
    if(!h)
    {
        return true;
    }
    Node* a = h;
    Node* b = h;
    while(b->next)
    {
        b = b->next;
    }
    while(a && b && a != b && b->next != a)
    {
        if(a->val != b->val)
        {
            return false;
        }
        a = a->next;
        b = b->prev;
    }
    return true;
}

int main()
{
    int n;
    char x;
    Node* h = nullptr;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        h = add_last(h, x);
    }

    cout << (is_pal(h) ? "True" : "False");
}