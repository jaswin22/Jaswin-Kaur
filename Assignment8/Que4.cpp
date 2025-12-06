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

bool check(Node* a, int mn, int mx)
{
    if(!a)
    {
        return true;
    }
    if(a->val <= mn || a->val >= mx)
    {
        return false;
    }
    return check(a->l, mn, a->val) && check(a->r, a->val, mx);
}

int main()
{
    Node* a = make_node(10);
    a->l = make_node(5);
    a->r = make_node(15);
    a->r->l = make_node(12);
    a->r->r = make_node(20);

    cout << (check(a, -1000000000, 1000000000) ? "YES" : "NO");
}

