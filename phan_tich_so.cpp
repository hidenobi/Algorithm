#include<bits/stdc++.h>
using namespace std;
int n, C[100], k, Stop=0;
void nhap(void){
	scanf("%d", &n);
	k = 1; C[k] = n;
}
void in(){
	cout << "(";
	for (int i = 1; i <= k; i++){
		if(i<k)	printf("%d ", C[i]);
		else printf("%d", C[i]);
	}
	cout <<")"<<" ";
}
void Sinhkt(){
	int i, j, R, S, D;
	i = k;
	while (i>0 && C[i] == 1){
		i--;
	}
	if (i>0){
		C[i] = C[i] - 1;
		D = k - i + 1;
		R = D / C[i];
		S = D % C[i];
		k = i;
		if (R>0){
			for (j = i + 1; j <= i + R; j++){
				C[j] = C[i];
			}
			k = k + R;
		}
		if (S>0){
			k = k + 1; C[k] = S;
		}
	}
	else Stop = 1;
	}

int main(){
	int t;
	cin >> t;
	while(t--){
		nhap();
		Stop = 0;
		while (!Stop){
			in();
			Sinhkt();
		}
		cout<<endl;
	}
 return 0;


}