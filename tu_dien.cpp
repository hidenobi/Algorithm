#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int k, n, m;
bool vis[5][5];
char a[5][5];
vector<string> ans;
string dic[105];
bool canVisit(int i, int j)
{
    return (i > 0 && j > 0 && i <= n && j <= m && !vis[i][j]);
}
void Clear()
{
    ans.clear();
    memset(vis, false, sizeof(vis));
}
void Try(string s, int r, int c)
{
    if (!canVisit(r, c))
        return;
    vis[r][c] = true;
    s += a[r][c];
    for (int i = 0; i < k; i++)
    {
        if (dic[i] == s)
            ans.push_back(s);
    }
    Try(s, r - 1, c - 1);
    Try(s, r - 1, c);
    Try(s, r - 1, c + 1);
    Try(s, r, c - 1);
    Try(s, r, c + 1);
    Try(s, r + 1, c - 1);
    Try(s, r + 1, c);
    Try(s, r + 1, c + 1);
    vis[r][c] = false;
}
void Solve()
{
    Clear();
    cin >> k >> n >> m;
    for (int i = 0; i < k; i++)
        cin >> dic[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            Try("", i, j);
    }
    if (ans.size() == 0)
        cout << -1 << "\n";
    else
    {
        for (auto x : ans)
            cout << x << " ";
        cout << "\n";
    }
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