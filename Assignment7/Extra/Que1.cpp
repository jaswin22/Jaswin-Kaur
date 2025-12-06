#include <iostream>
using namespace std;

void count_sort(int a[], int n)
{
    int mx = a[0];
    for(int i = 1; i < n; i++)
    {
        mx = a[i] > mx ? a[i] : mx;
    }

    int *c = new int[mx + 1];
    for(int i = 0; i <= mx; i++)
    {
        c[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        c[a[i]]++;
    }

    int k = 0;
    for(int i = 0; i <= mx; i++)
    {
        while(c[i]--)
        {
            a[k++] = i;
        }
    }

    delete[] c;
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

    count_sort(a, n);

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    delete[] a;
}
