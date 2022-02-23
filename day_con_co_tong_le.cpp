#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int b[10000];
void snt(int m){
	for(int i=0;i<m;i++) b[i]=1;
	b[0]=0;b[1]=0;
	for(int i=2;i<m;i++){
		if(b[i]){
			for(int j=i*i;j<m;j+=i) b[j]=0;
		}
	}
}
int n;
vector<int> a;
int check(string s){
	int sum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') sum+=a[i];
	}
	return (sum%2);
}
void init(){
	cin >> n;
	a.clear();
	a.resize(n);
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a.begin(),a.end(),greater<int>());
}
void Try(string s){
	if(s.size()==n){
		if(check(s)==1){
			for(int i=0;i<s.size();i++){
				if(s[i]=='1') cout << a[i] <<" ";
			}
			cout << "\n";
		}
	}
	else {
		Try(s+"0");
		Try(s+"1");
	}
}
void slove(){
	init();
	Try("");
}
int main(){
    fast;
    int t=1;
    cin >> t;
    snt(9999);
	while(t--){
		slove();
	}
    return 0;
}
