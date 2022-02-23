#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORD(i, a, b) for(int i = a; i > b; --i)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'
string s;
vector<int> pos;
int ok = 0;
int check(string str){
	int a = (str[0]-'0')*10+(str[1]-'0');
	int b = (str[5]-'0')*10+(str[6]-'0');
	int c = (str[10]-'0')*10+(str[11]-'0');
	char x = str[3];
	//cout << a << " " << b << " " << c << " " << x << endl;
	if(x == '+' && a + b == c) return 1;
	if(x == '-' && a - b == c) return 1;
	if(x == '*' && a * b == c) return 1;
	if(x == '/' && a % b == 0 && a / b == c) return 1;
	return 0;
}
void ql(int i, string str){
	if(ok) return;
	if(i == pos.size()){
		if(check(str)){
			cout << str << endl;
			ok = 1;	
		}
		return;
	}
	if(pos[i] == 3){
		string tmp = str;
		tmp[3] = '+';  ql(i+1, tmp); 
		tmp[3] = '-';  ql(i+1, tmp); 
		tmp[3] = '*';  ql(i+1, tmp); 
		tmp[3] = '/';  ql(i+1, tmp); 
	}
	else{
		char first = '0';
		if(pos[i] == 0 || pos[i] == 5 || pos[i] == 10)
			first = '1';
		for(char j = first; j <= '9'; j++){
			string tmp = str;
			tmp[pos[i]] = char(j);
			ql(i+1, tmp);
		}
	}
}
void solve(){
	scanf("\n");
	getline(cin, s);
	pos.clear();
	ok = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '?') pos.pb(i);
	}
	ql(0, s);
	if(!ok) cout << "WRONG PROBLEM!\n";
}
int main(){
	int t; cin >> t;
	while(t--)
		solve();
}