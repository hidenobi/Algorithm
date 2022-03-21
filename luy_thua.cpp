#include <bits/stdc++.h>
using namespace std;
long long du=1e9+7;
long long lt (long long a, long long b){
	if (b==0) return 1;
	if (b%2==0){
		long long p=lt (a, b/2);
		return (p*p)%du;
	}
		long long p=lt (a, b-1);
		return (p*a)%du;
}
 
int main (){
	long long a, b,t;
	// cin >> t;
	while (1)
	{
		cin>>a>>b;
		if (a==0 && b==0) break;
		cout<<lt(a, b)<<endl;
	}
	return 0;
}