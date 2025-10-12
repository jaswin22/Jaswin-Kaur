#include <iostream>
using namespace std;

bool substr(const char* s1, const char* s2)
{
    int len1 = 0, len2 = 0;

    while (s1[len1] != '\0') 
        ++len1;
    while (s2[len2] != '\0') 
        ++len2;
        
    if (len1 == 0)  
        return true;
    if (len1 > len2)
        return false;

    for (int i = 0; i <= len2 - len1; ++i)
    {
        int j = 0;
        while (j < len1 && s2[i + j] == s1[j])
            ++j;
        if (j == len1) 
            return true;
    }
    return false;
}

bool canSplit(const char* s)
{
    int n = 0;
    while (s[n] != '\0') ++n;

    for (int i = 1; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            char a[101], b[101], c[101];
            for (int k = 0; k < i; ++k) 
                a[k] = s[k];
            a[i] = '\0';
            for (int k = 0; k < j - i; ++k)
                b[k] = s[i + k];
            b[j - i] = '\0';
            for (int k = 0; k < n - j; ++k) 
                c[k] = s[j + k];
            c[n - j] = '\0';

            if ((substr(a, b) && substr(a, c)) || (substr(b, a) && substr(b, c)) || (substr(c, a) && substr(c, b)))
                return true;
        }
    }
    return false;
}

int main() {
    char s[101];
    cout << "Enter string: ";
    cin >> s;
    if (canSplit(s))
        cout << "YES\n";
    else
        cout << "NO\n";
}
