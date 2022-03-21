#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
using namespace std;
long long mod = 1e9 + 7;
void slove(){
    string s;
        cin >> s;
        stack<pair<char, int>> st;
        int ans = 0, n = s.size();
        vector<int> F(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ')' && !st.empty() && st.top().first == '(')
            {
                F[i] = F[i - 1];
                if (st.top().second != 0)
                    F[i] += F[st.top().second - 1];
                F[i] += 2;
                st.pop();
            }
            else
                st.push({s[i], i});
        }
        for (int i = 0; i < n; i++)
            ans = max(ans, F[i]);
        cout << ans << endl;
}
int main(){
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}