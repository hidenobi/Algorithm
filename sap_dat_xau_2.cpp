#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
void slove(){
    int d;
    string s;
    cin >> d >> s;
    int n = s.size();
    map<char, int> cnt;
    for (auto x : s)
        cnt[x]++;
    int biggest_fre = -1;
    for (auto x : cnt)
        biggest_fre = max(biggest_fre, x.second);
    cout << ((biggest_fre - 1) * (d - 1) > n - biggest_fre ? -1 : 1) << "\n";

}
int main(){
    int t;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}