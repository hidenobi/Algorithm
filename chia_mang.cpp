#include <bits/stdc++.h>
#include<unordered_set>
typedef long long ll;
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.1415926535897932384626433832795
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<ll,ll> pi;
#define endl "\n"
int n,k,sum=0;
int  bt(vi a,vi b,vi c,int dem,int index)
{
    if (c[dem]==sum)
    {
        if (dem==k-2) return 1;
        return bt(a,b,c,dem+1,n-1);
    }
    FORD(i,index,0)
    {
        if (b[i]==1)  continue;
        int tmp=c[dem]+a[i];
        if (tmp<=sum)
        {
            b[i]=1;
            c[dem]+=a[i];
            int m=bt(a,b,c,dem,i-1);
            b[i]=0;
            c[dem]-=a[i];
            if (m==1)  return true;
        }
    }
    return false;
}
int check(vi a)
{
 
    if (n<k) return 0;
    if (sum==0) return 1;
    if (k==1) return 1;
    if (sum%k!=0) return 0;
    sum/=k;
    vi c(k,0);
    vi b(n,0);
    c[0]+=a[n-1];
    b[n-1]=1;
    return bt(a,b,c,0,n-1);
    
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        sum=0;
        cin >> n >> k;
        vi a(n);
        
        FOR(i,0,n-1) {cin >> a[i];sum+=a[i];}
        sort(a.begin(),a.end());
        cout << check(a)<<endl;
        
        
    }
}