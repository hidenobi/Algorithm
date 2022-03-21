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
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<int> dp(n + 1);
    dp[1] = x;
    for (int i = 2; i <= n; i++)
        dp[i] = (i & 1 ? min(dp[i - 1] + x, dp[(i + 1) / 2] + z + y) : min(dp[i - 1] + x, dp[i / 2] + z));
    cout << dp[n] << "\n";
}
int main(){
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}