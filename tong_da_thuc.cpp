#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
map<int, int> m;
void Do(string s)
{
    s += ' ';
    int k1 = 0, k2 = 0, ok = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            if (ok == 0)
                k1 = k1 * 10 + s[i] - '0';
            else
                k2 = k2 * 10 + s[i] - '0';
        }
        else if (s[i] == '^')
            ok = 1;
        else if (s[i] == ' ')
        {
            m[k2] += k1;
            k1 = k2 = ok = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        m.clear();
        string a, b;
        getline(cin, a);
        getline(cin, b);
        Do(a);
        Do(b);
        vector<pair<int, int>> v;
        for (auto i : m)
            v.push_back(i);
        cout << v[v.size() - 1].second << "*x^" << v[v.size() - 1].first;
        for (int i = v.size() - 2; i >= 0; i--)
            cout << " + " << v[i].second << "*x^" << v[i].first;
        cout << endl;
    }
}