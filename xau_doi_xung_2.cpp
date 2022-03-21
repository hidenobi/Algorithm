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
    s = "-" + s;
    int dp[n + 5][n + 5];
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (i + 1 == j)
                dp[i][j] = (s[i] == s[j] ? 0 : 1);
            else
                dp[i][j] = (s[i] == s[j] ? dp[i + 1][j - 1] : min(dp[i][j - 1], dp[i + 1][j]) + 1);
        }
    }
    cout << dp[1][n] << "\n";
}
int main(){
    int t=1;
    cin >> t;
    cin.ignore();
    while(t--){
        slove();
    }
    return 0;
}