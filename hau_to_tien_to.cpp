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
    stack<string> a;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            string x = a.top();
            a.pop();
            string y = a.top();
            a.pop();
            string tmp = s[i] + y + x;
            a.push(tmp);
        }
        else
            a.push(string(1, s[i]));
    }
    cout << a.top() << "\n";
}
int main()
{
    int t = 1;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        slove();
    }
    return 0;
}