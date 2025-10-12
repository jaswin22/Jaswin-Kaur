#include <iostream>
using namespace std;

struct Node
{
    int d;
    Node* n;
};

void insEnd(Node*& h, int v)
{
    Node* p = new Node{v,nullptr};
    if(!h) { h=p; return; }
    Node* t=h;
    while(t->n) t=t->n;
    t->n=p;
}

void rev(Node*& h)
{
    Node *p=nullptr, *c=h, *n;
    while(c)
    {
        n=c->n;
        c->n=p;
        p=c;
        c=n;
    }
    h=p;
}

void disp(Node* h)
{
    while(h) { cout<<h->d<<"->"; h=h->n; }
    cout<<"NULL\n";
}

int main()
{
    Node* head=nullptr;
    int arr[]={1,2,3,4};
    for(int v:arr) insEnd(head,v);

    cout<<"Original: ";
    disp(head);

    rev(head);

    cout<<"Reversed: ";
    disp(head);

    return 0;
}
