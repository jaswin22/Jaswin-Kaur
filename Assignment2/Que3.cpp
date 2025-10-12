#include <iostream>
using namespace std;

int linearSearch(int a[], int n)
{
    for (int i=0; i < n; ++i)
    {
        if (a[i] != i+1)
            return i+1;
    }
    return n;
}

int binarySearch(int a[], int n)
{
    int l=0, r=n-1;
    while (l <= r)
    {
        int m=l+(r-l) / 2;
        if (a[m] == m+1)
            l=m+1;
        else
            r=m-1;
    }
    return l+1;
}

int main() {
    int a[10]={1, 2, 3, 5, 6};
    int n=6;
    cout<<"Missing (Linear): " <<linearSearch(a, n) <<endl;
    cout<<"Missing (Binary): " <<binarySearch(a, n);
}