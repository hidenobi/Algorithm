#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int>b){
    return a.second < b.second;
}
void slove(){
    int n;
    cin >> n;
    vector< pair<int,int> > a(n);
    for(int i=0;i<n;i++) cin >> a[i].first;
    for(int i=0;i<n;i++) cin >> a[i].second;
    sort(a.begin(),a.end(),cmp);
    int ans=1,en=a[0].second;
    for(int i=1;i<n;i++){
        if(a[i].first>=en){
            ans++;
            en=a[i].second;
        }
        if(a[i].second<en) en=a[i].second;
    }
    cout << ans << "\n";

}
int main(){
    int t;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}