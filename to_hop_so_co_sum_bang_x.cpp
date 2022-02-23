#include<bits/stdc++.h>
using namespace std;
int a[25]={},dem,b[25],n; 
void Try1(int i,int x){
	if(x==0){
		dem++;
		return;
	}
	if(i==n) return;
	for(int j=x/a[i];j>=0;j--){
		b[i]=j;
		Try1(i+1,x-a[i]*j);
		b[i]=0;
	}
}
void Try2(int i,int x){
	if(x==0){
		cout<<'['; 
		bool check=0;
		for(i=0;i<n;i++){
			for(int j=0;j<b[i];j++){
				if(check)cout<<' '<< a[i];
				else{
					check=1;cout<<a[i]; 
				} 
			} 
		} 
		cout<<"]";
		return; 
	}
	if(i==n) return;
	for(int j=x/a[i];j>=0;j--){
		b[i]=j;
		Try2(i+1,x-a[i]*j); 
		b[i]=0; 
	} 
} 
int main(){
	int t;
	cin >> t;
	while(t--){
		dem=0; 
		int x;
		cin>>n>>x;
		for(int i=0;i<n;i++){
			cin>>a[i];b[i]=0;
		}
		sort(a,a+n); 
		Try1(0,x);
		if(dem){
			// cout<<dem<<" ";  
            Try2(0,x); 
		}
        else cout<<"-1" ;
		cout<<endl; 
	}
	return 0;
}
