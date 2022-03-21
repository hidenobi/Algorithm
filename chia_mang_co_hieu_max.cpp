#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
void slove(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    int sum=0,s=0;
    for(auto &i:a){
        cin >> i;
        sum+=i;
    }
    sort(a.begin(),a.end(),greater<int>());
    k=max(k,n-k);
    for(int i=0;i<k;i++){
        s+=a[i];
    }
    
    cout << s-(sum-s) << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}