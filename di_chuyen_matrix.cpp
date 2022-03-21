#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int a[1002][1002],n,m,c[1002][1002]={0};
void slove(){
	c[1][1]=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin >> a[i][j];
	}
	queue <pair<int,int> > q;
	q.push(make_pair(1,1));
	while(!q.empty()){
		pair<int,int> p=q.front();q.pop();
		int i=p.first,j=p.second;
		if(c[i+a[i][j]][j]==-1){
			q.push(make_pair(i+a[i][j],j));
			c[i+a[i][j]][j]=c[i][j]+1;
		}
		if(c[i][j+a[i][j]]==-1){
			q.push(make_pair(i,j+a[i][j]));
			c[i][j+a[i][j]]=c[i][j]+1;
		}
		if(c[n][m]!=-1) break;
	}
	cout << c[n][m] << "\n";
}
int main(){
    fast;
    int t=1;
    cin >> t;
	while(t--){
		for(int i=0;i<=1000;i++){
			for(int j=0;j<=1000;j++) a[i][j]=0;
		}
		for(int i=0;i<=1000;i++){
			for(int j=0;j<=1000;j++) c[i][j]=-1;
		}
		slove();
	}
    return 0;
}

