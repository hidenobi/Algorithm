#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void slove(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v.push_back({a[i], i});
    }
    sort(v.begin(), v.end());
    int res = 1, temp = 1, c = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (v[i].second > c)
        {
            temp++;
            res = max(res, temp);
        }
        else
            temp = 1;
        c = v[i].second;
    }
    cout << n - res;
}
int main(){
    int t=1;
    // cin >> t;
    while(t--){
        slove();
    }
    return 0;
}