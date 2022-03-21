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
    stack<string> stk;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (isalpha(s[i]))
        {
            string tmp(1, s[i]);
            stk.push(tmp);
        }
        else
        {
            string a = stk.top();
            stk.pop();
            string b = stk.top();
            stk.pop();
            stk.push("(" + b + s[i] + a + ")");
        }
    }
    cout << stk.top() << "\n";
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