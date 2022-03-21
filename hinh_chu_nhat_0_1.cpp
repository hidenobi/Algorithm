#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <string>
using namespace std;
long long mod = 1e9 + 7;
void slove()
{
    int n, m, s = 1;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 1; j < n; j++)
            if (a[j][i] == 1)
                a[j][i] = a[j - 1][i] + 1;
    for (int i = 0; i < n; i++)
    {
        stack<int> b, c;
        int l[m], r[m];
        for (int j = 0; j < m; j++)
        {
            while (!b.empty() && a[i][j] <= a[i][b.top()])
                b.pop();
            if (b.empty())
                l[j] = 0;
            else
                l[j] = b.top() + 1;
            b.push(j);
        }
        for (int j = m - 1; j >= 0; j--)
        {
            while (!c.empty() && a[i][j] <= a[i][c.top()])
                c.pop();
            if (c.empty())
                r[j] = m - 1;
            else
                r[j] = c.top() - 1;
            c.push(j);
        }
        for (int j = 0; j < m; j++)
            s = max(s, (r[j] - l[j] + 1) * a[i][j]);
    }
    cout << s << endl;
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        slove();
    }
    return 0;
}