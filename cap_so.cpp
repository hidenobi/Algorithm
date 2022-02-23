#include <bits/stdc++.h>
#define LL long long 
#define ULL unsigned long long
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FO(i,a,b) for(int i=a;i<b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define debug cout << "YES" << endl
using namespace std;
 
typedef pair<int,int> pII;
typedef pair<LL,LL> pLL;
const int inf = 1e9;
const LL Linf = (LL) 1e18;
const LL MOD = 1000000007LL;
#define PI 3.141592653589793238;
#define maxn 1000005
 
struct SegmentTree {
	LL *A , n;
	LL *st;
	int left( int p ) {
		return p << 1;
	}
	int right ( int p ) {
		return ( p << 1 ) | 1;
	}
	SegmentTree(int n) {
		A = nullptr;
		st = new LL[4*n];
		FOR(i,1,4*n-1) {
			st[i] = 0;
		}
	}
	SegmentTree(LL _a[],int _n) {
		n = _n;
		A = _a;
		st = new LL[4*n];
		FOR(i,1,4*n-1) {
			st[i] = 0;
		}
	}
	void update(int p,int l,int r,int x) {
		if( r < x || l > x ) {
			return;
		}
		if( l == r ) {
			st[p]++;
			return;
		}
		int m = (l+r)/2;
		update(left(p),l,m,x);
		update(right(p),m+1,r,x);
		st[p] = st[left(p)] + st[right(p)];
	}
	int getSum(int p,int l,int r,int u,int v) {
		if( r < u || l > v ) {
			return 0;
		}
		if( u <= l && r <= v ) {
			return st[p];
		}
		int m = (l+r)/2;
		return getSum(left(p),l,m,u,v) + getSum(right(p),m+1,r,u,v);
	}
	~SegmentTree() {
		delete []st;
	}
};
 
void solve() {
	const int N = 1e6;
	int n;
	cin >> n;
	LL a[n+5];
	FOR(i,1,n) {
		cin >> a[i];
	}
	LL ans = 0;
	stack<LL> st;
	SegmentTree tree(N);
	FOR(i,1,n) {
		if( a[i]&1 ) {
			while( st.size() ) {
				tree.update(1,1,N,st.top());
				st.pop();
			}
		}
		else {
			ans += tree.getSum(1,1,N,a[i]+1,N);
			st.push(a[i]);
		}
	}
	cout << ans << endl;
}
 
int main(){
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
//    freopen("test.out","w",stdout);
#endif
	int T = 1;
//	cin >> T;
	while( T-- )
    	solve();
    return 0;
}