#include<bits/stdc++.h>
using namespace std;
int n,m;
typedef struct dat{
	int w,v;
} sv;
int main(){
	int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        sv a[1005];
        int dp[1100][1100]={0};
        int res=0;
        for(int i=1;i<=n;i++){
            cin >> a[i].w ;
        }
        for(int i=1;i<=n;i++){
            cin >> a[i].v ;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(j<a[i].w ) dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i].w ]+a[i].v );
                res=max(res,dp[i][j]);
            }
        }
        cout << res << "\n";
    }
	return 0;
}