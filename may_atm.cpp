#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false);
using namespace std;
int c[50]={},a[50]={},stop=0,s,n;
int Bsearch(int a[],int n,int k)
{
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(r+l)/2;
        if(a[mid]==k) return 1;
        if(a[mid]>k) r=mid-1;
        else l=mid+1;
    }
    return -1;
}
void sinh(int k)
{
    int i=k;
    while(i>0 && c[i]==n-k+i) i--;
    if(i<=0) stop=1;
    else
    {
        c[i]++;
        for(int j=i+1;j<=k;j++) c[j]=c[j-1]+1;
    }
}
int main()
{
    int t=1;
    cin >> t;
    while(t--){
    	stop=0;
    	cin>>n>>s;
	    for(int i=1;i<=n;i++) cin>>a[i];
	    sort(a,a+n);
	    if(Bsearch(a,n,s)==1) printf("1");
	    else
	    {
	    	int check=0;
	        for(int i=1;i<=n;i++)
	        {
	            stop=0;
	            for(int j=1;j<=i;j++) c[j]=j;
	            while(stop==0){
	                int res=0;
	                for(int j=1;j<=i;j++) res+=a[c[j]];
	                if(res==s){
	                    cout<<i;
	                    check=1;
	                   	break;
	                }
	                sinh(i);
	            }
	            if(check==1) break;
	        }
	        if(check==0) cout<<"-1";
	    }
    	cout << endl;
	}
	return 0;
}