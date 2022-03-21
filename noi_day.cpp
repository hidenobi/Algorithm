#include<bits/stdc++.h>
using namespace  std;
long long mod=1e9+7;
int main(){
    int t;
    cin >> t;
    while(t--){
        priority_queue<long long , vector<long long>, greater<long long> > a;
        int n;
        cin >> n;
        while(n--){
            long long x;
            cin >> x;
            a.push(x);
        }
        long long dem=0;
        while(a.size()>1){
            long long p=a.top();
            a.pop();
            long long q=a.top();
            a.pop();
            dem=(dem+p+q)%mod;
            a.push((p+q)%mod);
        }
        cout << dem%mod << "\n";
    }
    return 0;
}