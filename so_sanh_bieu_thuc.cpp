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
string Reverse_Sign(string tmp)
{
    for (int i = 0; i < (int)tmp.size(); i++)
    {
        if (tmp[i] == '-')
            tmp[i] = '+';
        else if (tmp[i] == '+')
            tmp[i] = '-';
    }
    return tmp;
}
string Remove_Bracket(string s)
{
    if (isalpha(s[0]) || s[0] == '(')
        s.insert(0, 1, '+');
    for (int i = 1; i < (int)s.size(); i++)
    {
        if ((s[i] == '(' && s[i - 1] == '(') || (isalpha(s[i]) && s[i - 1] == '('))
        {
            s.insert(i, 1, '+');
            i--;
        }
    }
    stack<string> stk;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == ')')
        {
            string tmp = "";
            while (!stk.empty() && stk.top() != "(")
            {
                tmp = stk.top() + tmp;
                stk.pop();
            }
            stk.pop();
            if (stk.top() == "-")
                tmp = Reverse_Sign(tmp);
            stk.pop();
            stk.push(tmp);
        }
        else
        {
            string tmp(1, s[i]);
            stk.push(tmp);
        }
    }
    string ans = "";
    while (!stk.empty())
    {
        ans = stk.top() + ans;
        stk.pop();
    }
    while (ans.front() == '+')
        ans.erase(0, 1);
    return ans;
}
void slove()
{
    string s1, s2;
    cin >> s1 >> s2;
    string rs1 = Remove_Bracket(s1);
    string rs2 = Remove_Bracket(s2);
    cout << (rs1 == rs2 ? "YES\n" : "NO\n");
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