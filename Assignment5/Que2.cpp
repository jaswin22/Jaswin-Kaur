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
    t->n = p;
}

void disp(Node* h)
{
    while(h) { cout<<h->d<<"->"; h=h->n; }
    cout<<"NULL\n";
}

void cntDel(Node*& h, int k)
{
    int cnt=0;
    Node* t=h;
    while(t) { if(t->d==k) cnt++; t=t->n; }
    cout<<"Count: "<<cnt<<"\n";

    while(h && h->d==k) { Node* p=h; h=h->n; delete p; }
    Node* prev=h;
    if(prev)
    {
        Node* cur=prev->n;
        while(cur)
        {
            if(cur->d==k) { prev->n=cur->n; delete cur; cur=prev->n; }
            else { prev=cur; cur=cur->n; }
        }
    }
}

int main()
{
    Node* head=nullptr;
    int arr[]={1,2,1,2,1,3,1};
    for(int v:arr) insEnd(head,v);

    disp(head);

    int key=1;
    cntDel(head,key);

    disp(head);
    return 0;
}
