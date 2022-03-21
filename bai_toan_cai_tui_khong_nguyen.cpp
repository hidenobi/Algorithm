#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
#define df double
using namespace std;
long long mod = 1e9 + 7;

bool cmp(pair<df,df> a,pair<df,df> b){
    df r1=a.first*1.0/a.second,r2=b.first*1.0/b.second;
    return r1>r2;
}
void slove(){
    int n;
    // cin >> n;
    df w;
    cin >> n >> w;
    vector< pair<df,df> > a(n);
    for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(),a.end(),cmp);
    df res=0;
    int i=0;
    while(w>=a[i].second&&i<n){
        res+=a[i].first;
        w-=a[i].second;
        i++;
    }
    res+=(i<n ? w*a[i].first*1.0/a[i].second : 0);
    printf("%.2lf\n",res);
}
int main(){
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}