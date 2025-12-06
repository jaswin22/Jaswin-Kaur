#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

Node* insert_last(Node* head, int x)
{
    Node* t = new Node;
    t->val = x;
    if(!head)
    {
        t->next = t;
        return t;
    }
    Node* c = head;
    while(c->next != head)
    {
        c = c->next;
    }
    c->next = t;
    t->next = head;
    return head;
}

void show(Node* head)
{
    if(!head)
    {
        return;
    }
    Node* c = head;
    do
    {
        cout << c->val << " ";
        c = c->next;
    }
    while(c != head);
    cout << head->val;
}

int main()
{
    Node* head = nullptr;
    int n, x;
    cin >> n;
    while(n--)
    {
        cin >> x;
        head = insert_last(head, x);
    }
    show(head);
}
