#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
using namespace std;
long long mod = 1e9 + 7;
vector<int> a(1e4+5,0);
int Ugly(int n){
    for(int i=1;i<=5;i++){
        if(i==n) return n;
    }
    set<long long> s;
    s.insert(1);
    n--;
    while(n){
        auto it = s.begin();
        long long x= *it;
        s.erase(it);
        s.insert(x*2);
        s.insert(x*3);
        s.insert(x*5);
        n--;
    }
    return *s.begin();
}
void slove(){
    int n;
    cin >> n;
    cout << Ugly(n) << "\n";
}
int main(){
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}