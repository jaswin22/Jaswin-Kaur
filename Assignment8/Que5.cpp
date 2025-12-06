#include <iostream>
using namespace std;

void heapify(int a[], int n, int i, bool inc)
{
    int p = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(inc)
    {
        if(l < n && a[l] > a[p]) p = l;
        if(r < n && a[r] > a[p]) p = r;
    }
    else
    {
        if(l < n && a[l] < a[p]) p = l;
        if(r < n && a[r] < a[p]) p = r;
    }

    if(p != i)
    {
        int t = a[i];
        a[i] = a[p];
        a[p] = t;
        heapify(a, n, p, inc);
    }
}

void heapsort(int a[], int n, bool inc)
{
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i, inc);
    }
    for(int i = n - 1; i >= 0; i--)
    {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        heapify(a, i, 0, inc);
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int order;
    cin >> order;

    heapsort(a, n, order == 1);

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    delete[] a;
}

