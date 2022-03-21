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
    vector< vector<int> > a;
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        vector<int> tmp;
        for(int j=0;j<m;j++){
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        a.push_back(tmp);
    }
    dp[0][0]=a[0][0];
    for(int i=1;i<n;i++) dp[i][0]=dp[i-1][0]+a[i][0];
    for(int i=1;i<m;i++) dp[0][i]=dp[0][i-1]+a[0][i];
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+a[i][j];
        }
    } 
    cout << dp[n-1][m-1] << "\n";
}
int main(){
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}