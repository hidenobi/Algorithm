#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
map<char, int> pri;
vector<ll> num;
bool isOperator(char c)
{
    return (c != '+' && c != '-' && c != '*' && c != '/' ? false : true);
}
string to_Suffix(string s)
{
    string res = "";
    stack<char> q;
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            q.push(s[i]);
        else if (s[i] == ')')
        {
            while (!q.empty() && q.top() != '(')
            {
                res += q.top();
                q.pop();
            }
            q.pop();
        }
        else if (isalpha(s[i]))
            res += s[i];
        else
        {
            while (!q.empty() && pri[s[i]] <= pri[q.top()] && isOperator(q.top()))
            {
                res += q.top();
                q.pop();
            }
            q.push(s[i]);
        }
    }
    while (!q.empty() && isOperator(q.top()))
    {
        res += q.top();
        q.pop();
    }
    return res;
}
void Split_Number(string &s)
{
    char *str = new char[s.size() + 1];
    strcpy(str, s.c_str());
    char *p = strtok(str, "+-*/()");
    while (p != NULL)
    {
        num.push_back(stoi(p));
        p = strtok(NULL, "+-*/()");
    }
    for (ll i = 0; i < num.size(); i++)
    {
        string tmp = to_string(num[i]);
        ll pos = s.find(tmp);
        ll len = tmp.size();
        s.replace(pos, len, "A");
    }
}
ll Calc(ll a, ll b, char x)
{
    if (x == '+')
        return (a + b);
    else if (x == '-')
        return (a - b);
    else if (x == '*')
        return (a * b);
    return (a / b);
}
void Solve()
{
    num.clear();
    string s;
    cin >> s;
    Split_Number(s);
    reverse(num.begin(), num.end());
    string suf = to_Suffix(s);
    stack<ll> stk;
    for (ll i = 0; i < suf.size(); i++)
    {
        if (suf[i] == 'A')
        {
            stk.push(num.back());
            num.pop_back();
            continue;
        }
        ll n2 = stk.top();
        stk.pop();
        ll n1 = stk.top();
        stk.pop();
        stk.push(Calc(n1, n2, suf[i]));
    }
    cout << stk.top() << "\n";
}
int main()
{
    pri['+'] = pri['-'] = 1;
    pri['*'] = pri['/'] = pri['%'] = 2;
    pri['^'] = 3;
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}