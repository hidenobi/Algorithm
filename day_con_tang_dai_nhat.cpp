#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], l[n], ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        l[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && l[i] <= l[j])
                l[i] = l[j] + 1;
        }
        ans = max(ans, l[i]);
    }
    cout << ans;
}