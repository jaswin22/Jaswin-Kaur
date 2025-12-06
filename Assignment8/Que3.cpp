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

Node* insert_node(Node* a, int x)
{
    if(!a)
    {
        return make_node(x);
    }
    if(x < a->val)
    {
        a->l = insert_node(a->l, x);
    }
    else if(x > a->val)
    {
        a->r = insert_node(a->r, x);
    }
    return a;
}

Node* min_node(Node* a)
{
    while(a && a->l)
    {
        a = a->l;
    }
    return a;
}

Node* delete_node(Node* a, int x)
{
    if(!a)
    {
        return a;
    }
    if(x < a->val)
    {
        a->l = delete_node(a->l, x);
    }
    else if(x > a->val)
    {
        a->r = delete_node(a->r, x);
    }
    else
    {
        if(!a->l)
        {
            Node* t = a->r;
            delete a;
            return t;
        }
        else if(!a->r)
        {
            Node* t = a->l;
            delete a;
            return t;
        }
        Node* t = min_node(a->r);
        a->val = t->val;
        a->r = delete_node(a->r, t->val);
    }
    return a;
}

int max_depth(Node* a)
{
    if(!a)
    {
        return 0;
    }
    int L = max_depth(a->l);
    int R = max_depth(a->r);
    return (L > R ? L : R) + 1;
}

int min_depth(Node* a)
{
    if(!a)
    {
        return 0;
    }
    int L = min_depth(a->l);
    int R = min_depth(a->r);
    if(!a->l || !a->r)
    {
        return (a->l ? L : R) + 1;
    }
    return (L < R ? L : R) + 1;
}

void inorder(Node* a)
{
    a ? (inorder(a->l), cout << a->val << " ", inorder(a->r)) : void();
}

int main()
{
    Node* a = nullptr;
    int n, x;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        a = insert_node(a, x);
    }

    cin >> x;
    a = delete_node(a, x);

    inorder(a);
    cout << endl;

    cout << max_depth(a) << endl;
    cout << min_depth(a) << endl;
}
