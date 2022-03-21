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
void slove(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i:a) cin >> i;
    int minn=*min_element(a.begin(),a.end());
    int ans=1e9;
    for(int i=1;i<=minn;i++){
        int x = 0;
        bool ok = true;
        for (int j = 0; j < n; j++){
            double temp1 = a[j] * 1.0 / i;
            double temp2 = a[j] * 1.0 / (i + 1);
            int temp = (int)temp2 + 1;
            if (temp <= temp1)
                x += temp;
            else{
                ok = false;
                break;
            }
        }
        if (ok) ans = min(ans, x);
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