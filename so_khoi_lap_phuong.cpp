#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll n, x[20];
string s;
ll ans;
unordered_map<ll, bool> isCube;
ll Make_Number()
{
    ll num = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (x[i])
            num = num * 10 + (s[i - 1] - '0');
    }
    return num;
}
void Try(ll k)
{
    if (k > n)
        return;
    for (ll i = 0; i < 2; i++)
    {
        x[k] = i;
        if (k == n)
        {
            ll num = Make_Number();
            if (isCube[num])
                ans = max(ans, num);
        }
        Try(k + 1);
    }
}
void Solve()
{
    cin >> s;
    n = s.size();
    ans = -1;
    Try(1);
    cout << (ans == 0 ? -1 : ans) << "\n";
}
int main()
{
    for (ll i = 1; i <= 1000000; i++)
        isCube[i * i * i] = true;
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}