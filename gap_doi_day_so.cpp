#include<bits/stdc++.h>
using namespace std;    
int main(){
	int t;
	cin >> t;
	while(t--){
		long long n,k;
		cin >> n >> k;
		if(k%2!=0) cout <<"1\n";
		else {
			long long i=1;
			long long x=2;
			while(k%x==0){
				i++;
				x=pow(2,i);
				
			}
			cout << i << endl;
		}
	}
	return 0;
}