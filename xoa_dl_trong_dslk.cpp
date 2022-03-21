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
    int k;
    cin >> k;
    for(auto i:a){
        if(i!=k) cout << i << " ";
    }
}
int main(){
    int t=1;
    // cin >> t;
    while(t--){
        slove();
    }
    return 0;
}