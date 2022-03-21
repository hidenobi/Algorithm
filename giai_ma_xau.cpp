#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
string Duplicate(string str, int d)
{
    string res = "";
    for (int i = 1; i <= d; i++)
        res += str;
    return res;
}
bool isNum(string num)
{
    char c = num[0];
    return isdigit(c);
}
void Solve()
{
    string s;
    cin >> s;
    if (s[0] == '[')
        s.insert(0, 1, '1');
    for (int i = 1; i < (int)s.size(); i++)
    {
        if (s[i] == '[' && !isdigit(s[i - 1]))
        {
            s.insert(i, 1, '1');
            i--;
        }
    }
    stack<string> stk;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] != ']')
        {
            string tmp(1, s[i]);
            stk.push(tmp);
            continue;
        }
        string m = "";
        while (!stk.empty() && stk.top() != "[")
        {
            m = stk.top() + m;
            stk.pop();
        }
        stk.pop();
        string d = "";
        while (!stk.empty() && isNum(stk.top()))
        {
            d = stk.top() + d;
            stk.pop();
        }
        int num = stoi(d);
        stk.push(Duplicate(m, num));
    }
    string res = "";
    while (!stk.empty())
    {
        res = stk.top() + res;
        stk.pop();
    }
    cout << res << "\n";
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