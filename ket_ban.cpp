#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int cnt;
void DFS(vector<bool> &vis, vector<int> adj[], int cur)
{
    vis[cur] = true;
    cnt++;
    for (auto x : adj[cur])
    {
        if (!vis[x])
            DFS(vis, adj, x);
    }
}
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());
    for (int i = 1; i <= n; i++)
        adj[i].resize(unique(adj[i].begin(), adj[i].end()) - adj[i].begin());
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cnt = 0;
            DFS(vis, adj, i);
            ans = max(ans, cnt);
        }
    }
    cout << ans << "\n";
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