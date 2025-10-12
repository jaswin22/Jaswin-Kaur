#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array length: ";
    cin >> n;
    int* a = new int[n];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int c = 0;
    for (int i = 0; i < n; ++i) {
        bool diff = true;
        for (int j = 0; j < i; ++j) {
            if (a[i] == a[j]) {
                diff = false;
                break;
            }
        }
        if (diff)
            ++c;
    }

    cout << "Total number of distinct elements: " << c << endl;
}

int main2()
{
    int a[10] = {1,2,3,4,5,6,7,8,10,10} , n = 10;

    int count = 0;
    for (int i = 0; i <n; i++)
    {
        while (i<n-1 && a[i]==a[i+1])
        {
            i++;
        }
        count++;
    }
    cout<<count;
}