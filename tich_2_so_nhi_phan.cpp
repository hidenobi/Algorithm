#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        long long s1 = 0, s2 = 0;
        long long n1 = a.size(), n2 = b.size();
        for (long long i = n1 - 1; i >= 0; i--)
            s1 += (a[i] - '0') * pow(2, n1 - i - 1);
        for (long long i = n2 - 1; i >= 0; i--)
            s2 += (b[i] - '0') * pow(2, n2 - i - 1);
        cout << s1 * s2 << endl;
    }
}