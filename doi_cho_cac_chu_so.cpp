#include <bits/stdc++.h>
#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define fori(i,a,b) for (int i = a; i < b; i++)
#define forr(i,a,b) for (ll i = a - 1; i >= b; i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
 
const ll mod = 1e9 + 7;
const ll oo = 1e6 + 5;
 
bool ok;
string res;
 
void Try(string s, int k, int i){
    if(k >= 0) {
        res = max(res, s);
    }
    if(k <= 0) return;
    if(i >= s.size()) return;
 
    ok = 1;
    fori(j, i + 1, s.size()){
        if(s[j] > s[i]) {
            ok = 0;
            swap(s[i], s[j]);
            Try(s, k - 1, i + 1);
            swap(s[i], s[j]);
        }
    }
    if(ok) Try(s, k, i + 1);
}
 
void xl (){
    string s;
    int k; res = "0";
    cin >> k >> s;
    Try(s, k, 0);
    cout << res;
}
 
int main(){
    fastIO();
    int T; 
    //T = 1;
    cin >> T;
    //cin.ignore();
    while (T -- ){
        xl();
        cout << "\n";
    }
}