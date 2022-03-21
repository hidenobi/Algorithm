#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
#define FORT(i,a,b) for(int i=a;i<b;i++)
using namespace std;
void slove(){
    int n,res=0;
    cin>>n;
    vector<int> f(n);
    vector<int> a(n);
    FORT(i,0,n) cin>>a[i];
    FORT(i,0,n)
    {
        f[i]=a[i];
        FORT(j,0,i) 
            if (a[j]<a[i]) f[i]=max(f[i],f[j]+a[i]);
    }
    FORT(i,0,f.size())
        res=max(res,f[i]);
    cout<<res<<endl;
}
int main(){
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}