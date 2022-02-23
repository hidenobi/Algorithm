#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void slove(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i:a) cin >> i;
    sort(a.begin(),a.end(),greater<int>());
    int mid=(n+1)/2;
    int l=0,r=mid,p=0;
    while(l<mid&&r<n){
        if(a[l]>=2*a[r]){
            p++;
            l++;r++;
        }
        else r++;
    }
    cout << n-p << "\n";
}
int main(){
    int test=1;
    cin >> test;
    while(test--){
        slove();
    }
    return 0;
}