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
#define ll long long
void slove()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    stack<ll> stk;
    vector<ll> l(n), r(n);
    for (ll i = 0; i < n; i++)
    {
        if (stk.empty())
        {
            stk.push(i);
            continue;
        }
        while (!stk.empty() && a[i] < a[stk.top()])
        {
            r[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while (!stk.empty())
    {
        r[stk.top()] = n;
        stk.pop();
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        if (stk.empty())
        {
            stk.push(i);
            continue;
        }
        while (!stk.empty() && a[i] < a[stk.top()])
        {
            l[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while (!stk.empty())
    {
        l[stk.top()] = -1;
        stk.pop();
    }
    ll res = -1;
    for (ll i = 0; i < n; i++)
        res = max(res, a[i] * (r[i] - l[i] - 1));
    cout << res << "\n";
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