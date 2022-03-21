#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void slove(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &i:a) cin >> i;
    sort(a.begin(),a.end());
    long long s[5];
    s[0]=a[0]*a[1];
    s[1]=a[0]*a[1]*a[2];
    s[2]=a[0]*a[1]*a.back();
    s[3]=a[a.size()-2]*a[a.size()-1];
    s[4]=a[a.size()-2]*a[a.size()-1]*a[a.size()-3];
    sort(s,s+5);
    cout << s[4] << " ";
}
int main(){
    int t=1;
    // cin >> t;
    while(t--){
        slove();
    }
    return 0;
}