#include <iostream>
using namespace std;

#define MAX 1000

void dailyTemp(int temp[], int n)
{
    int s[MAX], top = -1, res[MAX];
    for (int i = n - 1; i >= 0; i--)
    {
        while (top >= 0 && temp[s[top]] <= temp[i])
            top--;
        res[i] = (top == -1 ? 0 : s[top] - i);
        s[++top] = i;
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << endl;
}

int main()
{
    int temp[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = 8;
    dailyTemp(temp, n);
    return 0;
}
