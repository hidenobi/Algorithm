#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
    	int n,m;
    	cin >> n >> m;
    	int len=n+m;
    	vector<int> x(n+1),y(m+1),z(len,0);
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		for(int i=1;i<=m;i++){
			cin >> y[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				int u=x[i]*y[j];
				z[i+j-1]+=u;
			}
		}
		for(int i=0;i<len;i++){
			if(i!=0) cout << z[i] << " ";
		}
		cout << endl;
		x.clear();y.clear();z.clear();
	}
    return 0;
  
}