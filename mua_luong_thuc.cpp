#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void slove(){
    int n,s,m;
    cin >> n >> s >> m;
    if (n < m || 6 * (n - m) < m){
        cout << "-1\n";
        return;
    }
        
    cout <<  ceil((s * m) * 1.0 / n) << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}