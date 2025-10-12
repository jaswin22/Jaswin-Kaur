#include <iostream>
using namespace std;

#define MAX 1000

void nextBig(int arr[], int n)
{
    int s[MAX], top = -1, res[MAX];
    for (int i = n - 1; i >= 0; i--)
    {
        while (top >= 0 && s[top] <= arr[i])
            top--;
        res[i] = (top == -1 ? -1 : s[top]);
        s[++top] = arr[i];
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {6, 8, 0, 1, 3};
    int n = 5;
    nextBig(arr, n);
    return 0;
}
