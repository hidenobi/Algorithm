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
vector<vector<long long>> dp(105, vector<long long>(905));
void slove(){
    long long n,k;
    cin >> n >> k;
    if(k>900){
        cout << "0\n";
        return;
    }
    cout << dp[n][k] << "\n";
}
int main(){
    dp[0][0] = 1;
    for (int i = 1; i <= 100; i++){
        for (int j = 1; j <= 900; j++){
            for (int dig = 0; dig < 10; dig++){
                if (j >= dig)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - dig]) % mod;
            }
        }
    }
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}