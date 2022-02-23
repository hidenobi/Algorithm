#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
bool Check(string str)
{
    if (str.size() == 0)
        return false;
    if (str.size() == 1 && isalpha(str[0]))
        return false;
    int cnt = 0;
    for (int i = 0; i < (int)str.length(); i++)
    {
        if (str[i] == '(')
            cnt++;
        else if (str[i] == ')')
            cnt--;
        if (cnt < 0)
            return false;
    }
    return (cnt == 0);
}
void Solve()
{
    string s;
    cin >> s;
    vector<string> ans;
    unordered_set<string> diff;
    queue<string> q;
    diff.insert(s);
    q.push(s);
    bool mn = false;
    while (!q.empty())
    {
        string str = q.front();
        q.pop();
        if (Check(str))
        {
            ans.push_back(str);
            mn = true;
        }
        if (mn)
            continue;
        for (int i = 0; i < (int)str.size(); i++)
        {
            if (isalnum(str[i]))
                continue;
            string tmp = str.substr(0, i) + str.substr(i + 1);
            if (diff.find(tmp) == diff.end())
            {
                diff.insert(tmp);
                q.push(tmp);
            }
        }
    }
    if (ans.size() == 0)
    {
        cout << -1 << "\n";
        return;
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << " ";
    cout << "\n";
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