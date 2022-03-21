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
    int n = s.size();
    for (int i = 0; i <= n; i++)
    {
        if (s[i] == 'D')
            stk.push(i + 1);
        else if (s[i] == 'I' || i == n)
        {
            stk.push(i + 1);
            while (!stk.empty())
            {
                cout << stk.top();
                stk.pop();
            }
        }
    }
    cout << "\n";
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