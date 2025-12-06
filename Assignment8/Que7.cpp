#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *l, *r;
};

struct DNode
{
    int val;
    DNode *prev, *next;
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

void inorder(Node* a, int arr[], int &k)
{
    if(!a)
    {
        return;
    }
    inorder(a->l, arr, k);
    arr[k++] = a->val;
    inorder(a->r, arr, k);
}

DNode* add_last(DNode* h, int x)
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

int main()
{
    int n1, n2, x;
    cin >> n1;
    Node* a = nullptr;
    for(int i = 0; i < n1; i++)
    {
        cin >> x;
        a = insert_node(a, x);
    }

    cin >> n2;
    Node* b = nullptr;
    for(int i = 0; i < n2; i++)
    {
        cin >> x;
        b = insert_node(b, x);
    }

    int *A = new int[n1];
    int *B = new int[n2];
    int k1 = 0, k2 = 0;

    inorder(a, A, k1);
    inorder(b, B, k2);

    int i = 0, j = 0;
    DNode* h = nullptr;

    while(i < k1 && j < k2)
    {
        if(A[i] < B[j])
        {
            h = add_last(h, A[i++]);
        }
        else
        {
            h = add_last(h, B[j++]);
        }
    }

    while(i < k1)
    {
        h = add_last(h, A[i++]);
    }

    while(j < k2)
    {
        h = add_last(h, B[j++]);
    }

    DNode* c = h;
    while(c)
    {
        cout << c->val << " ";
        c = c->next;
    }

    delete[] A;
    delete[] B;
}
