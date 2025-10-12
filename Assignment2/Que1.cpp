#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int t) 
{
    int l = 0, r = n - 1;
    while (l <= r) 
    {
        int m = l + (r - l) / 2;
        if (a[m] == t)
            return m;
        if (a[m] < t)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main() 
{
    int n, t, a[50];

    cout<<"Please Enter the Number of elemnts you want in the new array ";
    cin>>n;
    for(int i = 0; i < n ; i++)
    {
        cout<<"\nElement "<<i+1<<" ";
        cin>>a[i];
    }
    cout<<"array Created Successfully \n";
    int ans = binarySearch(a, n, t);
    cout<<ans<<endl;
}
