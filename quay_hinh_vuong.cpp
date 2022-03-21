#include <bits/stdc++.h>
#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define fori(i,a,b) for (ll i = a; i < b; i++)
#define forr(i,a,b) for (ll i = a - 1; i >= b; i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;

const ll mod = 1e9 + 7;
const ll oo = 1e6 + 5;

string quay_trai(string a){
    string res = "";
    res = res + a[3] + a[0] + a[2] + a[4] + a[1] + a[5];
    return res;
}

string quay_phai(string a){
    string res = "";
    res = res + a[0] + a[4] + a[1] + a[3] + a[5] + a[2];
    return res;
}

string s, v;

void BFS(string u){
    map <string, int> vs;
    queue <string> q;
    q.push(u);
    vs[u] = 1;
    while (!q.empty()){
        u = q.front(); q.pop();
        if(u == s) {
            cout << vs[u] - 1;
            return;
        }
        v = quay_trai(u);
        if(!vs[v]) {
            vs[v] = vs[u] + 1;
            q.push(v);
        }
        v = quay_phai(u);
        if(!vs[v]) {
            vs[v] = vs[u] + 1;
            q.push(v);
        }
    }
    
}

int x;

void xl (){
    string u = "";
    fori(i, 0, 6){
        cin >> x;
        u = u + char (x + '0');
    }
    s = "";
    fori(i, 0, 6){
        cin >> x;
        s = s + char (x + '0');
    }
    //cout << quay_phai(u) << " " << quay_trai(u);
    BFS(u);
    
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