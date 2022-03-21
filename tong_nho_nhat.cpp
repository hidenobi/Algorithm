#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void slove(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i:a) cin >> i;
    sort(a.begin(),a.end());
    long long x=0,y=0;
    for(int i=0;i<a.size();i+=2) x=x*10+a[i];
    for(int i=1;i<a.size();i+=2) y=y*10+a[i];
    cout << x+y << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}