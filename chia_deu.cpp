#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.1415926535897932384626433832795
#define MOD 1e9+7
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
int n,sum,k;
int ans=0;
int S=0;
int a[15];
void dequy(int sum,int dem,int index,int now,int l)
{
    //cout << dem <<" "<<index<<" "<<now<<endl;
    if (index==n) return;
    if (dem==k-1)
    {
        ans++;
        return;
    }
    if (now==sum&&l==1)
    {
        
        dequy(sum,dem+1,index,0,0);
        
    }
    
    dequy(sum,dem,index+1,now+a[index],1);
}
int main()
{
    cin>> n>>k;
    FOR(i,0,n-1)
    {
        cin >> a[i];
        S+=a[i];
    }
    
    if (S%k!=0)
    {
        cout << 0;
        return 0;
    }
    if (k==1)
    {
        cout <<1;
        return 0;
    }
    sum=S/k;
    dequy(sum,0,0,0,0);
    cout << ans;
} 