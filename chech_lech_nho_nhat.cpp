#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
void slove(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    vector<int> b;
    for(int i=0;i<n-1;i++){
        b.push_back(a[i+1]-a[i]);
    }
    sort(b.begin(),b.end());
    cout << b[0];
    cout << "\n";
}
int main(){
    int test=1;
    cin >> test;
    while(test--){
        slove();
    }
    return 0;
}
