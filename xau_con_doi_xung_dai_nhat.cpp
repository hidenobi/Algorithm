#include<bits/stdc++.h>
using namespace std;
int findString(string s){
    int n=s.size();
    bool a[n][n];
    memset(a,0,sizeof(a));
    int maxx=1;
    for(int i=0;i<n;i++) a[i][i] = true;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            a[i][i+1]=true;
            maxx=2;
        }
    }
    for(int k=3;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            int j=i+k-1;
            if(a[i+1][j-1]&&s[i]==s[j]){
                a[i][j]=true;
                maxx=max(maxx,k);
            }
        }
    }
    return maxx;
}
void slove(){
    string s;
    cin >> s;
    cout << findString(s) << "\n";
}
int main(){
    int t;
    cin >> t;cin.ignore();
    while(t--){
        slove();
    }
    return 0;
}