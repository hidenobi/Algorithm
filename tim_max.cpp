#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long mod = 1e9+7;
void slove(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &i:a) cin >> i;
    sort(a.begin(),a.end());
    long long sum=0;
    for(int i=0;i<n;i++) {
        sum=(sum+a[i]*i)%mod;
    }
    cout << sum << "\n";
    
}
int main(){
    int t;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}