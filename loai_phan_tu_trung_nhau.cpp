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
    map<int,bool> m;
    for(auto &i:a) {
        cin >> i;
        m[i]=true;
    }
    for(auto i:a){
        if(m[i]==true){
            cout << i << " ";
            m[i]=false;
        }
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