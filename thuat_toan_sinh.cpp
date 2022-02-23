#include<bits/stdc++.h>
using namespace std;
int n;
int check(string s){
	string a=s;
	reverse(s.begin(),s.end());
	if(a==s) return 1;
	return 0;
}
void in(string s){
	for(int i=0;i<s.size();i++){
		cout << s[i] << " ";
	}
	cout << "\n";
}
void Try(string s){
	if(s.size()==n) {
		if(check(s)==1) in(s);
	}
	else {
		Try(s+"0");
		Try(s+"1");
	}
}
int main(){
	cin >> n;
	Try("");
	return 0;
}
