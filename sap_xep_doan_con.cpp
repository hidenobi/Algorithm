#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct dt
{
    int first;
    int second;
    int third;
};
bool cmp1(dt a, dt b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
bool cmp2(dt a, dt b)
{
    return a.second < b.second;
}
void slove(){
    int n, m = 0;
        cin >> n;
        vector<dt> a(n);
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end(), cmp1);
        for (int i = 0; i < n; i++)
            a[i].third = i + 1;
        sort(a.begin(), a.end(), cmp2);
        for (int i = 0; i < n - 1; i++)
        {
            m = max(m, a[i].third);
            if (i + 1 == m)
                ans.push_back(i + 1);
        }
        cout << ans.size() << endl;
        for (int i : ans)
            cout << i << ' ';
        cout << endl;

}
int main(){
    int test=1;
    cin >> test;
    while(test--){
        slove();
    }
    return 0;
}