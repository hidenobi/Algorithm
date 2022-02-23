#include <bits/stdc++.h>
using namespace std;
int c[20][20];
int n;
int visit[20];
int minkc=1e9+9,ans=1e9+9;
void back (int k,int u, int val)
{
	if(k==n)
	{
		int m=val+c[u][1];
		ans=min(ans,m);
		return;
	}
	int kcc=val+(n-k+1)*minkc;
	if(kcc>ans) return;
	for(int i=2;i<=n;i++)
	{
		if(visit[i]==0)
		{
			visit[i]=1;
			int kc=val+c[u][i];
			back(k+1,i,kc);
			visit[i]=0;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cin>>c[i][j];
			if(i!=j) minkc=min(minkc,c[i][j]);
		}
	}
	back(1,1,0);
	cout<<ans;
	return 0;
}
