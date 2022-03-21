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
    int n,m;
    cin >> n >> m;
    long long dp[30][30];
    for (int i = 0; i <= 25; i++)
        dp[i][0] = dp[0][i] = 1;
    dp[0][0] = 0;
    for (int i = 1; i <= 25; i++)
    {
        for (int j = 1; j <= 25; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
    cout << dp[n][m] << "\n";
}
int main(){
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}