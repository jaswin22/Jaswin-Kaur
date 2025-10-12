#include <iostream>
using namespace std;

class DiagonalMatrix {
    int* arr;
    int n;
public:
    DiagonalMatrix(int n) : n(n)
    {
        arr = new int[n]();
    }
    ~DiagonalMatrix()
    {
        delete[] arr;
    }
    void set(int i, int j, int val)
    {
        if (i == j) arr[i] = val;
    }
    int get(int i, int j) const
    {
        return (i == j) ? arr[i] : 0;
    }
};

class TridiagonalMatrix {
    int* arr;
    int n;
public:
    TridiagonalMatrix(int n) : n(n)
    {
        arr = new int[3 * n - 2]();
    }
    ~TridiagonalMatrix()
    {
        delete[] arr;
    }
    void set(int i, int j, int val)
    {
        if (i - j == 1) arr[i - 1] = val;
        if (i == j) arr[n - 1 + i] = val;
        if (j - i == 1) arr[2 * n - 1 + i] = val;
    }
    int get(int i, int j) const
    {
        if (i - j == 1) return arr[i - 1];
        if (i == j) return arr[n - 1 + i];
        if (j - i == 1) return arr[2 * n - 1 + i];
        return 0;
    }
};

class LowerTriangularMatrix {
    int* arr;
    int n;
public:
    LowerTriangularMatrix(int n) : n(n)
    {
        arr = new int[n * (n + 1) / 2]();
    }
    ~LowerTriangularMatrix()
    {
        delete[] arr;
    }
    void set(int i, int j, int val)
    {
        if (i >= j) arr[i * (i + 1) / 2 + j] = val;
    }
    int get(int i, int j) const
    {
        if (i >= j) return arr[i * (i + 1) / 2 + j];
        return 0;
    }
};

class UpperTriangularMatrix {
    int* arr;
    int n;
public:
    UpperTriangularMatrix(int n) : n(n)
    {
        arr = new int[n * (n + 1) / 2]();
    }
    ~UpperTriangularMatrix()
    {
        delete[] arr;
    }
    void set(int i, int j, int val)
    {
        if (i <= j) arr[i * n - (i * (i - 1)) / 2 + (j - i)] = val;
    }
    int get(int i, int j) const
    {
        if (i <= j) return arr[i * n - (i * (i - 1)) / 2 + (j - i)];
        return 0;
    }
};

class SymmetricMatrix {
    int* arr;
    int n;
public:
    SymmetricMatrix(int n) : n(n)
    {
        arr = new int[n * (n + 1) / 2]();
    }
    ~SymmetricMatrix()
    {
        delete[] arr;
    }
    void set(int i, int j, int val)
    {
        if (i >= j) arr[i * (i + 1) / 2 + j] = val;
        else arr[j * (j + 1) / 2 + i] = val;
    }
    int get(int i, int j) const
    {
        if (i >= j) return arr[i * (i + 1) / 2 + j];
        return arr[j * (j + 1) / 2 + i];
    }
};

int main()
{
    int n = 4;

    DiagonalMatrix dm(n);
    dm.set(0, 0, 1);
    dm.set(1, 1, 2);
    dm.set(2, 2, 3);
    dm.set(3, 3, 4);
    cout << "Diagonal Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << dm.get(i, j) << " ";
        cout << endl;
    }

    TridiagonalMatrix tdm(n);
    tdm.set(0, 0, 1);
    tdm.set(0, 1, 2);
    tdm.set(1, 0, 3);
    tdm.set(1, 1, 4);
    tdm.set(1, 2, 5);
    tdm.set(2, 1, 6);
    tdm.set(2, 2, 7);
    tdm.set(2, 3, 8);
    tdm.set(3, 2, 9);
    tdm.set(3, 3, 10);
    cout << "\nTridiagonal Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << tdm.get(i, j) << " ";
        cout << endl;
    }

    LowerTriangularMatrix ltm(n);
    int val = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            ltm.set(i, j, val++);
    cout << "\nLower Triangular Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << ltm.get(i, j) << " ";
        cout << endl;
    }

    UpperTriangularMatrix utm(n);
    val = 1;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            utm.set(i, j, val++);
    cout << "\nUpper Triangular Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << utm.get(i, j) << " ";
        cout << endl;
    }

    SymmetricMatrix sm(n);
    sm.set(0, 0, 1);
    sm.set(0, 1, 2);
    sm.set(0, 2, 3);
    sm.set(0, 3, 4);
    sm.set(1, 1, 5);
    sm.set(1, 2, 6);
    sm.set(1, 3, 7);
    sm.set(2, 2, 8);
    sm.set(2, 3, 9);
    sm.set(3, 3, 10);
    cout << "\nSymmetric Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << sm.get(i, j) << " ";
        cout << endl;
    }
}
