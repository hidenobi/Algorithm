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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<long long> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= k; i++){
        for (int j = 0; j < n; j++){
            if (i >= a[j]) dp[i] = (dp[i] + dp[i - a[j]]) % mod;
        }
    }
    cout << dp[k] << "\n";
}
int main(){
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}