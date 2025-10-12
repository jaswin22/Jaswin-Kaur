#include <iostream>
using namespace std;

int countPairsWithDiffK(const int arr[], int n, int k) {
    int count = 0;
    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (abs(arr[i] - arr[j]) == k)
                count++;
        }
    }
    return count;
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[1000];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "Enter value of k: ";
    cin >> k;

    int result = countPairsWithDiffK(arr, n, k);
    cout << "Number of pairs with difference " << k << " is: " << result << endl;
}
