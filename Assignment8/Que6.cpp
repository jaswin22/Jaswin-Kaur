#include <iostream>
using namespace std;

struct PQ
{
    int a[1000];
    int n;
};

void swap_val(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

void up(PQ &q, int i)
{
    while(i > 0)
    {
        int p = (i - 1) / 2;
        if(q.a[p] < q.a[i])
        {
            swap_val(q.a[p], q.a[i]);
            i = p;
        }
        else
        {
            break;
        }
    }
}

void down(PQ &q, int i)
{
    int l, r, m;
    while(true)
    {
        l = 2 * i + 1;
        r = 2 * i + 2;
        m = i;

        if(l < q.n && q.a[l] > q.a[m]) m = l;
        if(r < q.n && q.a[r] > q.a[m]) m = r;

        if(m == i) break;

        swap_val(q.a[i], q.a[m]);
        i = m;
    }
}

void push(PQ &q, int x)
{
    q.a[q.n] = x;
    up(q, q.n);
    q.n++;
}

int top(PQ &q)
{
    return q.n ? q.a[0] : -1;
}

void pop(PQ &q)
{
    if(!q.n) return;
    q.a[0] = q.a[q.n - 1];
    q.n--;
    down(q, 0);
}

int main()
{
    PQ q;
    q.n = 0;

    int t, x;
    cin >> t;

    while(t--)
    {
        int c;
        cin >> c;

        if(c == 1)
        {
            cin >> x;
            push(q, x);
        }
        else if(c == 2)
        {
            cout << top(q) << endl;
        }
        else if(c == 3)
        {
            pop(q);
        }
    }
}