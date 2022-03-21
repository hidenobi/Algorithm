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
vector< vector<long long> > v;
void Init(){
    for(long long i=0;i<16;i++){
        vector<long long> tmp;
        for(auto x:{1000,2000,3000,5000}){
            tmp.push_back(x*pow(10,i));
        }
        v.push_back(tmp);
    }
}
void slove(){
    long long n,c;
    cin >> n >> c;
    if(n%1000!=0){
        cout << "0\n";
        return;
    }
    map<long long,long long > m;
    long long ans=0, res=1;
    for(int i=c;i>=0;i--){
        for(int j=3;j>=0;j--){
            if(n>=v[i][j]){
                long long d=n/v[i][j];
                m[v[i][j]]=d;
                ans+=d;
                n-=(d*v[i][j]);
            }
        }
    }
    for(int i=0;i<16;i++){
        long long q=1;
        bool ok1=false,ok2=false,ok3=false;
        for(int j=0;j<4;j++){
            if(j==0&&m[v[i][j]]>0) ok1=true;
            if(j==2&&m[v[i][j]]>0) ok2=true;
            if(j==3&&m[v[i][j]]>0) ok3=true;
        }
        if(ok1==true&&ok2==true&&ok3==true) q=3;
        else if(ok1==true&&(ok2==true||ok3==true)) q=2;
        res*=q;
    }
    cout << ans << " " << res << '\n';
}
int main(){
    Init();
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}