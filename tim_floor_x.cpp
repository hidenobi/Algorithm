#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void slove(){
    int n;
    long long k;
    cin >> n;
    vector<long long> a(n);
    cin >> k;
    for(auto &i:a) cin >> i;
    sort(a.begin(),a.end());
    int low= lower_bound(a.begin(),a.end(),k)-a.begin();
    if(low==0&&a[low]!=k){
        cout << "-1\n";
        return;
    }
    if(low<n&&a[low]==k) cout << low + 1;
    else cout << low ;
    cout << "\n";
}
int main(){
    int test=1;
    cin >> test;
    while(test--){
        slove();
    }
    return 0;
}