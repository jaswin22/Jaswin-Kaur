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

Node* mid(Node* h)
{
    Node *s=h, *f=h;
    while(f && f->n)
    {
        s=s->n;
        f=f->n->n;
    }
    return s;
}

int main()
{
    Node* head=nullptr;
    int arr[]={1,2,3,4,5};
    for(int v:arr) insEnd(head,v);

    Node* m=mid(head);
    if(m) cout<<"Middle: "<<m->d<<"\n";
    return 0;
}
