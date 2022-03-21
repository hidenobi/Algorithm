#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include <climits>
using namespace std;
long long mod = 1e9 + 7;
void slove(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<int>> dp(n, vector<int>(k, INT_MIN));
    dp[0][a[0] % k] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i] %= k;
        for (int j = 0; j < k; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j + k - a[i]) % k] + 1);
    }
    cout << dp[n - 1][0] << "\n";
}
int main(){
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}