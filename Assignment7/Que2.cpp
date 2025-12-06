#include <iostream>
using namespace std;

void improved(int a[], int n)
{
    int l = 0, r = n - 1;

    while(l < r)
    {
        int mn = l, mx = l;
        for(int i = l; i <= r; i++)
        {
            mn = a[i] < a[mn] ? i : mn;
            mx = a[i] > a[mx] ? i : mx;
        }

        int t = a[l];
        a[l] = a[mn];
        a[mn] = t;

        if(mx == l)
        {
            mx = mn;
        }

        t = a[r];
        a[r] = a[mx];
        a[mx] = t;

        l++;
        r--;
    }
}

void show(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
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

    improved(a, n);
    show(a, n);

    delete[] a;
}