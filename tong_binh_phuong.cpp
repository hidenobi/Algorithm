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
 vector<vector<long long>> dp(105, vector<long long>(15, 0));
void slove(){
    int n;
    cin >> n;
    long long ans=0;
    for(int i=0;i<10;i++){
        ans=(ans+dp[n][i])%mod;
    }
    cout << ans << '\n';
}
int main(){
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= 100; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = j; k >= 0; k--)
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
        }
    }
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}