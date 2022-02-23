#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
bool Check(string s)
{
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (i != 0 && i != s.size() - 1 && (s[i] == 'A' || s[i] == 'E'))
        {
            if (s[i - 1] != 'A' && s[i - 1] != 'E' && s[i + 1] != 'A' && s[i + 1] != 'E')
                return false;
        }
    }
    return true;
}
int main()
{
    char c;
    cin >> c;
    string s = "";
    for (char i = 'A'; i <= c; i++)
        s += i;
    do
    {
        if (Check(s))
            cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));

    return 0;
}