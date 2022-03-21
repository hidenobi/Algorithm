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
    string s;
    cin >> s;
    stack<int> stk;
    int ans = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '(')
            stk.push(i);
        else
        {
            if (!stk.empty())
            {
                ans++;
                stk.pop();
            }
        }
    }
    cout << ans * 2 << "\n";
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