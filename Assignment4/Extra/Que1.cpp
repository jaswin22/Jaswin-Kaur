#include <iostream>
using namespace std;

void genBin(int n)
{
    for (int num = 1; num <= n; num++)
    {
        int temp = num;
        char bin[32];
        int index = 0;
        while (temp > 0)
        {
            bin[index++] = (temp % 2) ? '1' : '0';
            temp /= 2;
        }
        for (int i = index - 1; i >= 0; i--)
            cout << bin[i];
        cout << " ";
    }
    cout << endl;
}

int main()
{
    int n = 6;
    genBin(n);
    return 0;
}
