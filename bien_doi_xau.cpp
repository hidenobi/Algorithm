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
    string a,b;
    cin >> a >> b;
    int m=a.size(),n=b.size();
    int dp[m+1][n+1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) dp[i][j] = j; 
            else if (j == 0) dp[i][j] = i; 
            else if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1+ min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
        }
    }
    cout << dp[m][n] << "\n";
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