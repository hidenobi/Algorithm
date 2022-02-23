#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, k, ans = 0;
int a[200], b[200];
void backtracking(int pos1, int pos2)
{
    if (pos2 == k)
    {
        ans++;
        return;
    }
    for (int i = pos1 + 1; i < n; i++)
    {
        if (a[i] > a[pos1])
        {
            b[pos2 + 1] = a[i];
            backtracking(i, pos2 + 1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        b[0] = a[i];
        backtracking(i, 1);
    }
    cout << ans;
}