#include<iostream>
using namespace std;
int n,dem=0,hang[101],cot[101],chinh[201],phu[201];
void nhap(){
	cin >> n;
	for(int i=1;i<=n;i++){
		hang[i]=1;
		cot[i]=1;
	}
	for(int i=1;i<2*n;i++){
		chinh[i]=1;
		phu[i]=1;
	}
}
void Try(int i){
	for(int j=1;j<=n;j++){
		if(cot[j]&&chinh[i-j+n]&&phu[i+j-1]){
			cot[j]=0;
			chinh[i-j+n]=0;
			phu[i+j-1]=0;
			if(i==n) dem++;
			else Try(i+1);
			cot[j]=1;
			chinh[i-j+n]=1;
			phu[i+j-1]=1;
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		nhap();
		dem=0;
		Try(1);
		cout<< dem<<endl;
	}
	return 0;
}