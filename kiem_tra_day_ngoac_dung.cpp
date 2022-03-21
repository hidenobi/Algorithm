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
    int ok = 1;
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            if (st.size() && st.top() == '(')
                st.pop();
            else
            {
                ok = 0;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (st.size() && st.top() == '[')
                st.pop();
            else
            {
                ok = 0;
                break;
            }
        }
        else
        {
            if (st.size() && st.top() == '{')
                st.pop();
            else
            {
                ok = 0;
                break;
            }
        }
    }
    if (st.size())
        ok = 0;
    if (ok == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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