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
int LCS(string a, string b, string c){
    int x=a.size(),y=b.size(),z=c.size();
    int dp[x+1][y+1][z+1];
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            for(int k=0;k<=z;k++){
                if(i==0||j==0||k==0) dp[i][j][k]=0;
                else if((a[i-1]==b[j-1])&&b[j-1]==c[k-1]) dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                else dp[i][j][k]=max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
            }
        }
    }
    return dp[x][y][z];
}
void slove(){
    int x,y,z;
    cin >> x >> y >> z;
    cin.ignore();
    string a,b,c;
    cin >> a >> b >> c;
    cout << LCS(a,b,c) << "\n";
    // cout << a << b << c << "\n";
}
int main(){
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}