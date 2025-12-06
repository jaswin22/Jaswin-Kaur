#include <iostream>
using namespace std;

struct DNode
{
    int val;
    DNode *prev, *next;
};

DNode* d_insert_first(DNode* head, int x)
{
    DNode* t = new DNode;
    t->val = x;
    t->prev = nullptr;
    t->next = head;
    head ? head->prev = t : void();
    return t;
}

DNode* d_insert_last(DNode* head, int x)
{
    if(!head)
    {
        return d_insert_first(head, x);
    }
    DNode* c = head;
    while(c->next)
    {
        c = c->next;
    }
    DNode* t = new DNode;
    t->val = x;
    t->next = nullptr;
    t->prev = c;
    c->next = t;
    return head;
}

DNode* d_insert_after(DNode* head, int key, int x)
{
    DNode* c = head;
    while(c && c->val != key)
    {
        c = c->next;
    }
    if(!c)
    {
        return head;
    }
    DNode* t = new DNode;
    t->val = x;
    t->next = c->next;
    t->prev = c;
    c->next ? c->next->prev = t : void();
    c->next = t;
    return head;
}

DNode* d_insert_before(DNode* head, int key, int x)
{
    if(!head)
    {
        return head;
    }
    if(head->val == key)
    {
        return d_insert_first(head, x);
    }
    DNode* c = head;
    while(c && c->val != key)
    {
        c = c->next;
    }
    if(!c)
    {
        return head;
    }
    DNode* t = new DNode;
    t->val = x;
    t->prev = c->prev;
    t->next = c;
    c->prev->next = t;
    c->prev = t;
    return head;
}

DNode* d_delete_val(DNode* head, int x)
{
    if(!head)
    {
        return head;
    }
    if(head->val == x)
    {
        DNode* t = head->next;
        t ? t->prev = nullptr : void();
        delete head;
        return t;
    }
    DNode* c = head;
    while(c && c->val != x)
    {
        c = c->next;
    }
    if(!c)
    {
        return head;
    }
    c->prev->next = c->next;
    c->next ? c->next->prev = c->prev : void();
    delete c;
    return head;
}

bool d_search(DNode* head, int x)
{
    DNode* c = head;
    while(c)
    {
        if(c->val == x)
        {
            return true;
        }
        c = c->next;
    }
    return false;
}

void d_display(DNode* head)
{
    DNode* c = head;
    while(c)
    {
        cout << c->val << " ";
        c = c->next;
    }
    cout << endl;
}

struct CNode
{
    int val;
    CNode *next;
};

CNode* c_insert_first(CNode* head, int x)
{
    CNode* t = new CNode;
    t->val = x;
    if(!head)
    {
        t->next = t;
        return t;
    }
    CNode* c = head;
    while(c->next != head)
    {
        c = c->next;
    }
    t->next = head;
    c->next = t;
    return t;
}

CNode* c_insert_last(CNode* head, int x)
{
    return head ? (CNode*)([&]{
        CNode* c = head;
        while(c->next != head)
        {
            c = c->next;
        }
        CNode* t = new CNode;
        t->val = x;
        t->next = head;
        c->next = t;
        return head;
    }()) : c_insert_first(head, x);
}

CNode* c_insert_after(CNode* head, int key, int x)
{
    if(!head)
    {
        return head;
    }
    CNode* c = head;
    do
    {
        if(c->val == key)
        {
            CNode* t = new CNode;
            t->val = x;
            t->next = c->next;
            c->next = t;
            return head;
        }
        c = c->next;
    }
    while(c != head);
    return head;
}

CNode* c_delete_val(CNode* head, int x)
{
    if(!head)
    {
        return head;
    }
    CNode* c = head;
    CNode* p = nullptr;
    do
    {
        if(c->val == x)
        {
            if(!p)
            {
                CNode* t = head;
                while(t->next != head)
                {
                    t = t->next;
                }
                if(t == head)
                {
                    delete head;
                    return nullptr;
                }
                t->next = head->next;
                CNode* nh = head->next;
                delete head;
                return nh;
            }
            p->next = c->next;
            delete c;
            return head;
        }
        p = c;
        c = c->next;
    }
    while(c != head);
    return head;
}

bool c_search(CNode* head, int x)
{
    if(!head)
    {
        return false;
    }
    CNode* c = head;
    do
    {
        if(c->val == x)
        {
            return true;
        }
        c = c->next;
    }
    while(c != head);
    return false;
}

void c_display(CNode* head)
{
    if(!head)
    {
        cout << endl;
        return;
    }
    CNode* c = head;
    do
    {
        cout << c->val << " ";
        c = c->next;
    }
    while(c != head);
    cout << endl;
}

int main()
{
    DNode* d_head = nullptr;
    CNode* c_head = nullptr;
    int ch, type, x, y;

    while(true)
    {
        cin >> type;
        cin >> ch;

        if(type == 1)
        {
            if(ch == 1) cin >> x, d_head = d_insert_first(d_head, x);
            else if(ch == 2) cin >> x, d_head = d_insert_last(d_head, x);
            else if(ch == 3) cin >> y >> x, d_head = d_insert_after(d_head, y, x);
            else if(ch == 4) cin >> y >> x, d_head = d_insert_before(d_head, y, x);
            else if(ch == 5) cin >> x, d_head = d_delete_val(d_head, x);
            else if(ch == 6) cin >> x, cout << (d_search(d_head, x) ? "YES" : "NO") << endl;
            else if(ch == 7) d_display(d_head);
        }
        else
        {
            if(ch == 1) cin >> x, c_head = c_insert_first(c_head, x);
            else if(ch == 2) cin >> x, c_head = c_insert_last(c_head, x);
            else if(ch == 3) cin >> y >> x, c_head = c_insert_after(c_head, y, x);
            else if(ch == 5) cin >> x, c_head = c_delete_val(c_head, x);
            else if(ch == 6) cin >> x, cout << (c_search(c_head, x) ? "YES" : "NO") << endl;
            else if(ch == 7) c_display(c_head);
        }
    }
}
