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
void slove()
{
    int n;
    cin >> n;
    stack<int> st;
    vector<int> a(n), b(n, -1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[i] > a[st.top()])
        {
            b[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] == -1)
            cout << -1 << " ";
        else
            cout << a[b[i]] << " ";
    }
    cout << endl;
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