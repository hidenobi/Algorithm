#include<bits/stdc++.h>
using namespace std;
 
vector<long long> v;
void XuLy(long long n)
{
	long long temp = 2 ;
	while( n/2 > 0 )
	{
		v.push_back(temp);
		temp *= 2;
		n /= 2;
	}
}
long long check(long long i,long long n,int pos)
{
	// không dùng hàm log nữa bị TLE 
	if( i&1 ) return 1;
	if( i == v[pos] )
	{
		return n%2;
	}
	else if( i < v[pos] )
	{
		return check(i,n/2,pos-1);
	}
	else return check(i-v[pos],n/2,pos-1);
}
int main()
{	
	ios_base::sync_with_stdio(false);  cin.tie(NULL);
	int t;
	cin >> t;
	while( t-- )
	{
		long long n , l, r;
		cin >> n >> l >> r;
		v.clear();
		XuLy(n);
		long long dem = 0 , pos = v.size() - 1;
		for(long long i = l ; i <= r ; i++ )
		{
			dem += check(i,n,pos);
		}
		cout << dem << '\n' ;
	} 
}