#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n, seven = 0, four = 0;
    string s = "";
    cin >> n;
    for (int i = 0; i <= n / 4; i++)
    {
        int j = (n - 4 * i) / 7;
        if (7 * j + 4 * i == n)
        {
            seven = j;
            four = i;
            break;
        }
    }
    s.insert(s.size(), four, '4');
    s.insert(s.size(), seven, '7');
    cout << (s.size() == 0 ? "-1" : s) << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}