#include <bits/stdc++.h>
using namespace std;
const long long base = 1000000007;
int n;
struct MaTran{
    long long c[11][11];
};
 
MaTran operator * (MaTran a, MaTran b){
    MaTran res;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++){
            res.c[i][j] = 0;
            for (int k=0; k<n; k++)
                res.c[i][j] = (res.c[i][j]+a.c[i][k]*b.c[k][j])%base;
        }
    return res;
}
MaTran powermod (MaTran a, long long n){
    if (n==1)    	return a;
    if (n%2!=0)   	return powermod(a,n-1)*a;
    MaTran tmp = powermod(a,n/2);
    return tmp*tmp;
}
int main(){
    int t;
	cin >> t;
	while(t--){
		long long u;
	    cin >> n >> u;
	    MaTran A;
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<n;j++){
	    		cin >> A.c[i][j];
			}
		}
	    A = powermod(A,u);
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<n;j++){
	    		cout<< A.c[i][j]<<" ";
			}
			cout<<endl;
		}
	} 
    return 0;
}