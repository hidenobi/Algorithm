#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void slove(){
    string m;
    cin >> m;
    int n=m.size();
    vector<int> a(n+1);
    a[0]=1;a[1]=1;
    if(m[0]=='0') {
        cout << "0\n";
        return;
    }
    for(int i=2;i<=n;i++){
        a[i]=0;
        if(m[i-1]>'0') a[i]=a[i-1];
        if(m[i-2]=='1'||(m[i-2]=='2'&&m[i-1]<'7')) a[i]+=a[i-2];
    }
    cout << a[n] << "\n";
}
int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        slove();
    }
    return 0;
}