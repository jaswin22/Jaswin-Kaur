#include <iostream>
using namespace std;

#define MAX 1000

bool checkSorted(int A[], int n)
{
    int S[MAX], top = -1, B[MAX], id_A = 0, id_B = 0;
    for (int exp = 1; exp <= n; )
    {
        if (id_A < n && A[id_A] == exp)
        {
            B[id_B++] = A[id_A++];
            exp++;
        }
        else if (top >= 0 && S[top] == exp)
        {
            B[id_B++] = S[top--];
            exp++;
        }
        else if (id_A < n)
        {
            S[++top] = A[id_A++];
        }
        else
            break;
    }
    return id_B == n;
}

int main()
{
    int A[] = {5, 1, 2, 3, 4};
    int n = 5;
    cout << (checkSorted(A, n) ? "Yes" : "No") << endl;
    return 0;
}
