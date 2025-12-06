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
    x < a->val ? a->l = insert_node(a->l, x) : a->r = insert_node(a->r, x);
    return a;
}

Node* search_rec(Node* a, int x)
{
    if(!a || a->val == x)
    {
        return a;
    }
    return x < a->val ? search_rec(a->l, x) : search_rec(a->r, x);
}

Node* search_non(Node* a, int x)
{
    while(a && a->val != x)
    {
        a = x < a->val ? a->l : a->r;
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

Node* max_node(Node* a)
{
    while(a && a->r)
    {
        a = a->r;
    }
    return a;
}

Node* successor(Node* root, int x)
{
    Node* cur = root;
    Node* s = nullptr;

    while(cur)
    {
        if(x < cur->val)
        {
            s = cur;
            cur = cur->l;
        }
        else if(x > cur->val)
        {
            cur = cur->r;
        }
        else
        {
            if(cur->r)
            {
                return min_node(cur->r);
            }
            return s;
        }
    }
    return nullptr;
}

Node* predecessor(Node* root, int x)
{
    Node* cur = root;
    Node* p = nullptr;

    while(cur)
    {
        if(x > cur->val)
        {
            p = cur;
            cur = cur->r;
        }
        else if(x < cur->val)
        {
            cur = cur->l;
        }
        else
        {
            if(cur->l)
            {
                return max_node(cur->l);
            }
            return p;
        }
    }
    return nullptr;
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
    Node* r1 = search_rec(a, x);
    Node* r2 = search_non(a, x);
    Node* mn = min_node(a);
    Node* mx = max_node(a);
    Node* ss = successor(a, x);
    Node* pp = predecessor(a, x);

    cout << (r1 ? r1->val : -1) << endl;
    cout << (r2 ? r2->val : -1) << endl;
    cout << (mn ? mn->val : -1) << endl;
    cout << (mx ? mx->val : -1) << endl;
    cout << (ss ? ss->val : -1) << endl;
    cout << (pp ? pp->val : -1) << endl;
}
