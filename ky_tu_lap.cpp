#include<bits/stdc++.h>
using namespace std;
int n,MIN=1e9;
vector<string> s(11);
vector<string> a(11);
int check[11]={0};
void nhap(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
}
int sosanh(string a, string b){
	int dem[222]={0},res=0;
	for(int i=0;i<a.size();i++){
		dem[a[i]]=1;
	}
	for(int i=0;i<b.size();i++){
		if(dem[b[i]]==1) res++;
	}
	return res;
}
void sinh(int tong, int t){
	if(t<=n){
		if(tong<MIN){
			for(int i=1;i<=n;i++){
				if(check[i]==0){
					a[t]=s[i];
					check[i]=1;
					sinh(tong+sosanh(a[t],a[t-1]),t+1);
					check[i]=0;
				}
			}
		}
	}
	else MIN=min(tong,MIN);
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	nhap();
	sinh(0,1);
	cout << MIN;
}
