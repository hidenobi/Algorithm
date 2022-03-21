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
    int a[n][m];
    int s[n][m];
    int maxs;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> a[i][j];
    }
    for(int i=0;i<n;i++) s[i][0]=a[i][0];
    for(int i=0;i<m;i++) s[0][i]=a[0][i];
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j]==1){
                s[i][j]=min({s[i][j-1],s[i-1][j],s[i-1][j-1]})+1;
            }
            else s[i][j]=0;
        }
    }
    maxs=s[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maxs<s[i][j]) maxs=s[i][j];
        }
    }
    cout << maxs << "\n";
}
int main(){
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}