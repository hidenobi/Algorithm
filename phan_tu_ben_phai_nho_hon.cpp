#include <bits/stdc++.h>
using namespace std;
void maxx(int a[], int n, int next[], char order)
{
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && ((order == 'G') ? a[s.top()] <= a[i] : a[s.top()] >= a[i]))
        {
            s.pop();
        }
        if (!s.empty())
            next[i] = s.top();
        else
            next[i] = -1;
        s.push(i);
    }
}
void minmax(int a[], int n)
{
    int G[n], S[n];
    maxx(a, n, G, 'G');
    maxx(a, n, S, 'S');
    for (int i = 0; i < n; i++)
    {
        if (G[i] != -1 && S[G[i]] != -1)
        {
            cout << a[S[G[i]]] << ' ';
        }
        else
            cout << "-1"
                 << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        minmax(a, n);
        cout << "\n";
    }
    return 0;
}