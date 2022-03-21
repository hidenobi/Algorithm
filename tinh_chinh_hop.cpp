#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long mod = 1e9 + 7;
void slove(){
    long long n,k;
    cin >> n >> k;
    long long p=1;
    for(long long i=0;i<k;i++){
        p=(p*(n-i))%mod;
    }
    cout << p%mod << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}