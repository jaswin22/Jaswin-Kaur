#include <iostream>
using namespace std;

int countStudents(int students[], int sandwiches[], int n)
{
    int count = 0, i = 0, j = 0;
    int remaining = n;
    while (remaining > 0 && count < remaining)
    {
        if (students[i] == sandwiches[j])
        {
            j++;
            i = (i + 1) % n;
            remaining--;
            count = 0;
        }
        else
        {
            i = (i + 1) % n;
            count++;
        }
    }
    return remaining;
}

int main()
{
    int students[] = {1, 1, 0, 0};
    int sandwiches[] = {0, 1, 0, 1};
    int n = 4;
    cout << countStudents(students, sandwiches, n) << endl;
    return 0;
}
