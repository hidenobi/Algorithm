#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
ll Merge(ll a[], ll l, ll mid, ll r)
{
    ll lenl = mid - l + 1, lenr = r - mid;
    ll L[lenl], R[lenr];
    for (ll i = 0; i < lenl; i++)
        L[i] = a[i + l];
    for (ll i = 0; i < lenr; i++)
        R[i] = a[i + mid + 1];
    ll i = 0, j = 0, k = l;
    ll ans = 0;
    while (i < lenl && j < lenr)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
        {
            a[k++] = R[j++];
            ans += (lenl - i);
        }
    }
    while (i < lenl)
        a[k++] = L[i++];
    while (j < lenr)
        a[k++] = R[j++];
    return ans;
}
ll Inversion_Pair(ll a[], ll l, ll r)
{
    ll res = 0;
    if (l < r)
    {
        ll mid = (l + r) / 2;
        res += Inversion_Pair(a, l, mid);
        res += Inversion_Pair(a, mid + 1, r);
        res += Merge(a, l, mid, r);
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        cout << Inversion_Pair(a, 0, n - 1) << "\n";
    }
    return 0;
}