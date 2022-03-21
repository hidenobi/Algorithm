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
    vector<pair<int, int>> a(n);
    for (auto &x : a)
        cin >> x.first >> x.second;
    sort(a.begin(), a.end());
    int cnt = 1, last = a[0].second;
    for (int i = 1; i < n; i++)
    {
        if (a[i].first > last)
        {
            cnt++;
            last = a[i].second;
        }
        else if (a[i].second < last)
            last = a[i].second;
    }
    cout << cnt << "\n";
}
int main(){
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}