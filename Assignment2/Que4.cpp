#include <iostream>
using namespace std;

void concat2()
{
    char s1[100], s2[100];
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    int i = 0, j = 0;
    while (s1[i] != '\0')
        i++;
    while (s2[j] != '\0')
    {
        s1[i] = s2[j];
        i++; j++;
    }
    s1[i] = '\0';
    cout << "Concatenated string: " << s1 << endl;
}

void reverse()
{
    char str[100];
    cout << "Enter a string to reverse: ";
    cin >> str;
    int n = 0;
    while (str[n] != '\0') n++;
    for (int i = 0; i < n / 2; ++i)
    {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
    cout << "Reversed string: " << str << endl;
}

void deleteS()
{
    char str[100], result[100];
    cout << "Enter a string: ";
    cin >> str;
    int j = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        char lower = str[i];
        if (lower >= 'A' && lower <= 'Z')
            lower = lower + ('a' - 'A');
        if (lower != 'a' && lower != 'e' && lower != 'i' && lower != 'o' && lower != 'u')
            result[j++] = str[i];
    }
    result[j] = '\0';
    cout << "String without vowels: " << result << endl;
}

void sortS()
{
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    char arr[100][100];
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter string " << i + 1 << ": ";
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            int k = 0;
            while (arr[j][k] == arr[j + 1][k] && arr[j][k] != '\0' && arr[j + 1][k] != '\0')
                k++;
            if (arr[j][k] > arr[j + 1][k])
            {
                char temp[100];
                int l = 0;
                while (arr[j][l] != '\0') { temp[l] = arr[j][l]; l++; }
                temp[l] = '\0';
                l = 0;
                while (arr[j + 1][l] != '\0') { arr[j][l] = arr[j + 1][l]; l++; }
                arr[j][l] = '\0';
                l = 0;
                while (temp[l] != '\0') { arr[j + 1][l] = temp[l]; l++; }
                arr[j + 1][l] = '\0';
            }
        }
    }
    cout << "Strings in alphabetical order:" << endl;
    for (int i = 0; i < n; ++i)
        cout << arr[i] << endl;
}

void caseC()
{
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;
    if (ch >= 'A' && ch <= 'Z')
        ch = ch + ('a' - 'A'), cout << "Lowercase character: " << ch << endl;
    else
        cout << "Not an uppercase character." << endl;
}

int main()
{
    int choice;
    do
    {
        cout << "\nString Related Programs Menu:" << endl;
        cout << "1. Concatenate strings" << endl;
        cout << "2. Reverse a string" << endl;
        cout << "3. Delete vowels from string" << endl;
        cout << "4. Sort strings alphabetically" << endl;
        cout << "5. Uppercase to lowercase" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                concat2();
                break;
            case 2:
                reverse();
                break;
            case 3:
                deleteS();
                break;
            case 4:
                sortS();
                break;
            case 5:
                caseC();
                break;
            case 0:
                break;
            default: 
                cout << "Invalid choice." << endl;
        }
    } while (choice != 0);
}