#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int n, x[15], brac;
string s;
vector<pair<int, int>> bracket;
set<string> ans;
string Make()
{
    vector<bool> q(n, true);
    for (int i = 0; i < brac; i++)
    {
        if (x[i])
            q[bracket[i].first] = q[bracket[i].second] = false;
    }
    string res = "";
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (q[i])
            res += s[i];
    }
    return res;
}
void Try(int k)
{
    if (k == brac)
        return;
    for (int i = 0; i < 2; i++)
    {
        x[k] = i;
        if (k == brac - 1)
        {
            string tmp = Make();
            if (tmp != s)
                ans.insert(tmp);
        }
        else
            Try(k + 1);
    }
}
int main()
{
    cin >> s;
    brac = 0;
    n = s.size();
    stack<int> stk;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '(')
            stk.push(i);
        else if (s[i] == ')')
        {
            bracket.push_back({stk.top(), i});
            stk.pop();
        }
    }
    brac = bracket.size();
    Try(0);
    for (auto x : ans)
        cout << x << "\n";
    return 0;
}