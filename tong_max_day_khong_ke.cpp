#include <bits/stdc++.h>
using namespace std;
long long FindMaxSum(vector<long long> arr, long long n){
    long long incl = arr[0];
    long long excl = 0;
    long long excl_new;
    int i;
    for (i = 1; i < n; i++){
        excl_new = (incl > excl) ? incl : excl;
        incl = excl + arr[i];
        excl = excl_new;
    }
    return ((incl > excl) ? incl : excl);
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		vector<long long> a(n);
		for(long long i=0;i<n;i++) cin >> a[i];
    	cout<<FindMaxSum(a, n)<<endl;
	}
    return 0;
}