#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void slove(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x:a){
        cin >> x;
    }
    // vector<int> dp(k,0);
    // for(auto i:a){
    //     dp[i%k]++;
    // }
    // int sum=(dp[0]*dp[0]-1)/2;
    // for(int i=1;i<=k/2&&i!=(k-i);i++){
    //     sum+=dp[i]*dp[k-i];
    // }
    // if(k%2==0) sum+=(dp[k/2]*(dp[k/2]-1)/2);
    // cout << sum <<  '\n';
    int dem=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==k) dem++;
        }
    }
    cout << dem << "\n";
}
int main(){
    int test=1;
    cin >> test;
    while(test--){
        slove();
    }
    return 0;
}