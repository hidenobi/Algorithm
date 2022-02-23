#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
void slove(){
   int n, k;
    cin >> n >> k;
    vector<int> a(n);
    long long s = 0;
    map<int, long long> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    for (auto i : m)
    {
        if (i.first * 2 == k)
            s += i.second * (i.second - 1);
        else
            s += i.second * m[k - i.first];
    }
    cout << s / 2 << endl;
}
int main(){
    int test=1;
    cin >> test;
    while (test--){
        slove();
    }
    return 0;
}