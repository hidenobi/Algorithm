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
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long s1=0,s2=0,ss=0;
    int k1=0,k2=0;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            ss++;
            s1=s1+i-k1;
            k1=i;
        }
    }
    int p=0;
    string b;
    for(int i=n-1;i>=0;i--){
        b.push_back(s[i]);
    }
    for(int i=1;i<b.size();i++){
        if(b[i]!=b[i-1]){
            s2=s2+i-k2;
            k2=i;
        }
    }
    long long ans=n*(n-1)/2-s1-s2+ss;
    cout << ans << "\n";
}
int main(){
    int t=1;
    // cin >> t;
    while(t--){
        slove();
    }
    return 0;
}