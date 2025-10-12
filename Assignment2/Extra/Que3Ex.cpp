#include <iostream>
using namespace std;

bool areAnagrams(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;

    for (int i = 0; i < str1.length() - 1; i++) {
        for (int j = 0; j < str1.length() - i - 1; j++) {
            if (str1[j] > str1[j + 1])
            {
                char temp = str1[j];
                str1[j] = str1[j + 1];
                str1[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < str2.length() - 1; i++) {
        for (int j = 0; j < str2.length() - i - 1; j++) {
            if (str2[j] > str2[j + 1])
            {
                char temp = str2[j];
                str2[j] = str2[j + 1];
                str2[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i])
            return false;
    }
    return true;
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    if (areAnagrams(str1, str2))
        cout << "The strings are anagrams." << endl;
    else
        cout << "The strings are not anagrams." << endl;
}
