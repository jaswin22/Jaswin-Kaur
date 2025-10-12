#include <iostream>
using namespace std;

int inversions(int a[], int n) {
    int count = 0;
    for(int i = 0; i < n - 1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(a[i] > a[j])
                ++count;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[1000];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    cout << "Number of inversions: " << inversions(a, n) << endl;
}