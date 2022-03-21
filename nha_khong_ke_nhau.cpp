#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void slove(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i:a) cin >> i;
    if(n==0){
        cout << "0\n";
        return;
    }
    if(n==1){
        cout << a[0] << "\n";
        return;
    }
    if(n==2){
        cout << max(a[0],a[1]) << "\n";
        return;
    }
    vector<int> dp(n);
    dp[0]=a[0];
    dp[1]=max(a[0],a[1]);
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-2]+a[i],dp[i-1]);
    }
    cout << dp[n-1] << "\n"; 
}
int main(){
    int t;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}