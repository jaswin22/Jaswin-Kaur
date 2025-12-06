#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *l, *r;
};

Node* make_node(int x)
{
    Node* t = new Node;
    t->val = x;
    t->l = nullptr;
    t->r = nullptr;
    return t;
}

void pre(Node* a)
{
    if(a)
    {
        cout << a->val << " ";
        pre(a->l);
        pre(a->r);
    }
}

void in(Node* a)
{
    if(a)
    {
        in(a->l);
        cout << a->val << " ";
        in(a->r);
    }
}

void post(Node* a)
{
    if(a)
    {
        post(a->l);
        post(a->r);
        cout << a->val << " ";
    }
}

int main()
{
    Node* a = make_node(1);
    a->l = make_node(2);
    a->r = make_node(3);
    a->l->l = make_node(4);
    a->l->r = make_node(5);

    pre(a);
    cout << endl;
    in(a);
    cout << endl;
    post(a);
}
