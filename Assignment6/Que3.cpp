#include <iostream>
using namespace std;

struct DNode
{
    int val;
    DNode *prev, *next;
};

struct CNode
{
    int val;
    CNode *next;
};

DNode* d_insert_last(DNode* h, int x)
{
    DNode* t = new DNode;
    t->val = x;
    t->next = nullptr;
    if(!h)
    {
        t->prev = nullptr;
        return t;
    }
    DNode* c = h;
    while(c->next)
    {
        c = c->next;
    }
    c->next = t;
    t->prev = c;
    return h;
}

CNode* c_insert_last(CNode* h, int x)
{
    CNode* t = new CNode;
    t->val = x;
    if(!h)
    {
        t->next = t;
        return t;
    }
    CNode* c = h;
    while(c->next != h)
    {
        c = c->next;
    }
    c->next = t;
    t->next = h;
    return h;
}

int d_size(DNode* h)
{
    int c = 0;
    while(h)
    {
        c++;
        h = h->next;
    }
    return c;
}

int c_size(CNode* h)
{
    if(!h)
    {
        return 0;
    }
    int c = 0;
    CNode* t = h;
    do
    {
        c++;
        t = t->next;
    }
    while(t != h);
    return c;
}

int main()
{
    int n, x;
    DNode* dh = nullptr;
    CNode* ch = nullptr;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        dh = d_insert_last(dh, x);
    }

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        ch = c_insert_last(ch, x);
    }

    cout << d_size(dh) << endl;
    cout << c_size(ch) << endl;
}