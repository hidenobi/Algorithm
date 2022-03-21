#include <bits/stdc++.h>
using namespace std;
int LCS(string S1, string S2)
{
    int e = S1.size(), f = S2.size(), n;
    if (e > f)
        n = e;
    else
        n = f;
    int F[n + 1][n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            F[i][j] = 0;
        }
    }
    for (int i = 0; i < S1.length(); i++)
    {
        for (int j = 0; j < S2.length(); j++)
        {
            if (S1[i] == S2[j])
                F[i + 1][j + 1] = F[i][j] + 1;
            else
                F[i + 1][j + 1] = max(F[i][j + 1], F[i + 1][j]);
        }
    }
    return F[S1.length()][S2.length()];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        cout << LCS(a, b) << endl;
    }
}