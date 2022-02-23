#include<bits/stdc++.h>
using namespace std;
long long G[100];
char fibo(int n,long long i){
	if(n==1) return '0';
	if(n==2) return '1';
	if(i<=G[n-2]) return fibo(n-2,i);
	return fibo(n-1,i-G[n-2]);
}
int main(){
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin >> t;
	G[1]=1;
	G[2]=1;
	for(int i=3;i<93;i++){
		G[i]=G[i-1]+G[i-2];
	}
	while(t--){
		int n;
		long long i;
		cin >> n >> i;
		cout << fibo(n,i)<<endl;
	}
	return 0;
}