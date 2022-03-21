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
    int n = s.size();
    long long ans = 0;
    vector<long long> dp(n);
    dp[0] = s[0] - '0';
    ans += dp[0];
    for (int i = 1; i < (int)s.size(); i++)
    {
        dp[i] = (i + 1) * (s[i] - '0') + 10 * dp[i - 1];
        ans += dp[i];
    }
    cout << ans << "\n";
}
int main(){
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}