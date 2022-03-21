#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
using namespace std;
long long mod = 1e9 + 7;
void slove(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i:a) cin >> i;
    int ans=-1e9;
    vector<int> maxx(n), minn(n);
    for(int i=0;i<n;i++){
        maxx[i]=a[i];
        minn[i]=a[i];
    } 
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]&&minn[i]<minn[j]+a[i]) minn[i]=minn[j]+a[i];
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(a[i]>a[j]&&maxx[i]<maxx[j]+a[i]) maxx[i]=maxx[j]+a[i];
        }
    }
    for(int i=0;i<n;i++){
        ans=max(ans,maxx[i]+minn[i]-a[i]);
    }
    cout << ans << '\n';
}
int main(){
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}