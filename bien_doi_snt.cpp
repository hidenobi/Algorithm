#include<bits/stdc++.h>
 
using namespace std;
#define PB push
const int limit=1e5; 
bool F[limit+5]={};
int n,m;
void sang()
{
	F[0]=F[1]=1; 
	for(int i=2;i*i<limit;i++)
	{
		if(!F[i])
			for(int j=i*i;j<limit;j+=i) F[j]=1;
	} 
} 
int solve()
{ 
	if(n==m)return 0; 
	queue<int> q;queue<int> b;
	int a[5]={};
	bool check[limit+5]={}; 
	q.PB(n);b.PB(0); 
	while(!q.empty())
	{
		int u=q.front();
		//cout<<u<<endl; 
		check[u]=1; 
		a[3]=u%10;a[2]=(u/10)%10;a[1]=(u/100)%10;a[0]=(u/1000);
		for(int j=0;j<10;j++)
		{
			for(int i=0;i<4;i++)
			{
				if(!i&&!j)continue; 
				int sum=0; 
				for(int k=0;k<4;k++)
				{
					sum*=10; 
					if(k==i)sum+=j;
					else sum+=a[k]; 
				} 
				if(sum==m){
					return b.front()+1; 
				}
				if(!F[sum]&&!check[sum])
				{
					q.PB(sum);b.PB(b.front()+1); 
				} 
			} 
		} 
		b.pop();  q.pop();
	} 
}  
int main()
{
	sang(); 
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cout<< solve()<<endl; 
	} 
}