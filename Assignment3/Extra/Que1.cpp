#include <iostream>
using namespace std;

#define MAX 1000

void nearsmall(int arr[], int n)
{
    int s[MAX], top = -1;
    for (int i = 0; i < n; i++)
    {
        while (top >= 0 && s[top] >= arr[i])
            top--;
        cout << (top == -1 ? -1 : s[top]) << " ";
        s[++top] = arr[i];
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 5, 2, 10, 8};
    int n = 5;
    nearsmall(arr, n);
    return 0;
}
