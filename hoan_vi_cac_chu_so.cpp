#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int Calc(int n, int k, vector<string> a, vector<int> per)
{
    vector<int> num;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        for (int j = 0; j < k; j++)
            tmp += a[i][per[j]];
        num.push_back(stoi(tmp));
    }
    sort(num.begin(), num.end());
    return (num.back() - num.front());
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    vector<int> per(k);
    for (auto &x : a)
        cin >> x;
    for (int i = 0; i < k; i++)
        per[i] = i;
    int res = INT_MAX;
    do
    {
        res = min(res, Calc(n, k, a, per));
    } while (next_permutation(per.begin(), per.end()));
    cout << res;
    return 0;
}