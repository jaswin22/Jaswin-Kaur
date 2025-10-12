#include <iostream>
using namespace std;

struct Node
{
    int d;
    Node* n;
};

void insBeg(Node*& h, int v);
void insEnd(Node*& h, int v);
void insAft(Node* h, int t, int v);
void insBef(Node*& h, int t, int v);
void delBeg(Node*& h);
void delEnd(Node*& h);
void delNode(Node*& h, int v);
int search(Node* h, int v);
void disp(Node* h);

int main()
{
    Node* head = nullptr;
    int ch, v, t;

    do
    {
        cout << "\n1.InsBeg 2.InsEnd 3.InsAft 4.InsBef 5.DelBeg 6.DelEnd 7.DelNode 8.Search 9.Disp 0.Exit\n";
        cout << "Choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                cout << "Val: "; cin >> v;
                insBeg(head,v);
                break;
            case 2:
                cout << "Val: "; cin >> v;
                insEnd(head,v);
                break;
            case 3:
                cout << "Target Val: "; cin >> t;
                cout << "Val: "; cin >> v;
                insAft(head,t,v);
                break;
            case 4:
                cout << "Target Val: "; cin >> t;
                cout << "Val: "; cin >> v;
                insBef(head,t,v);
                break;
            case 5:
                delBeg(head);
                break;
            case 6:
                delEnd(head);
                break;
            case 7:
                cout << "Val: "; cin >> v;
                delNode(head,v);
                break;
            case 8:
                cout << "Val: "; cin >> v;
                int pos;
                pos = search(head,v);
                if(pos==-1) cout << "Not Found\n";
                else cout << "Pos: " << pos << "\n";
                break;
            case 9:
                disp(head);
                break;
        }

    } while(ch!=0);

    return 0;
}

void insBeg(Node*& h, int v)
{
    Node* p = new Node{v,h};
    h = p;
}

void insEnd(Node*& h, int v)
{
    Node* p = new Node{v,nullptr};
    if(!h) { h = p; return; }
    Node* t = h;
    while(t->n) t=t->n;
    t->n = p;
}

void insAft(Node* h, int tval, int v)
{
    Node* t = h;
    while(t && t->d!=tval) t=t->n;
    if(!t) { cout << "Not Found\n"; return; }
    Node* p = new Node{v,t->n};
    t->n = p;
}

void insBef(Node*& h, int tval, int v)
{
    if(!h) return;
    if(h->d==tval) { insBeg(h,v); return; }
    Node* t = h;
    while(t->n && t->n->d!=tval) t=t->n;
    if(!t->n) { cout << "Not Found\n"; return; }
    Node* p = new Node{v,t->n};
    t->n = p;
}

void delBeg(Node*& h)
{
    if(!h) return;
    Node* t = h;
    h = h->n;
    delete t;
}

void delEnd(Node*& h)
{
    if(!h) return;
    if(!h->n) { delete h; h=nullptr; return; }
    Node* t = h;
    while(t->n->n) t=t->n;
    delete t->n;
    t->n = nullptr;
}

void delNode(Node*& h, int v)
{
    if(!h) return;
    if(h->d==v) { delBeg(h); return; }
    Node* t = h;
    while(t->n && t->n->d!=v) t=t->n;
    if(!t->n) { cout << "Not Found\n"; return; }
    Node* p = t->n;
    t->n = t->n->n;
    delete p;
}

int search(Node* h, int v)
{
    int pos=1;
    while(h)
    {
        if(h->d==v) return pos;
        h=h->n;
        pos++;
    }
    return -1;
}

void disp(Node* h)
{
    while(h)
    {
        cout << h->d << "->";
        h=h->n;
    }
    cout << "NULL\n";
}
