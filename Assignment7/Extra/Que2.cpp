#include <iostream>
using namespace std;

int get_max(int a[], int n)
{
    int m = a[0];
    for(int i = 1; i < n; i++)
    {
        m = a[i] > m ? a[i] : m;
    }
    return m;
}

void count_exp(int a[], int n, int e)
{
    int c[10];
    for(int i = 0; i < 10; i++)
    {
        c[i] = 0;
    }

    int *o = new int[n];

    for(int i = 0; i < n; i++)
    {
        c[(a[i] / e) % 10]++;
    }

    for(int i = 1; i < 10; i++)
    {
        c[i] += c[i - 1];
    }

    for(int i = n - 1; i >= 0; i--)
    {
        int d = (a[i] / e) % 10;
        o[--c[d]] = a[i];
    }

    for(int i = 0; i < n; i++)
    {
        a[i] = o[i];
    }

    delete[] o;
}

void radix_sort(int a[], int n)
{
    int mx = get_max(a, n);
    for(int e = 1; mx / e > 0; e *= 10)
    {
        count_exp(a, n, e);
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

    radix_sort(a, n);

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    delete[] a;
}
