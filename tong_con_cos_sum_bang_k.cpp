#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n + 5], l[k + 5] = {};
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        l[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = k; j >= a[i]; j--)
            {
                if (l[j] == 0 && l[j - a[i]] == 1)
                    l[j] = 1;
            }
        }
        if (l[k] == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}