#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const ll mod = 1e15 + 7;

struct mat {
	int x, y;
	ll a[5][5];
};

ll solve(ll x, ll y) {
	if (x == 0 || y == 0) return 0;
	string X = "", Y = "", Z;
	for (; x>0; x/=10) X = X + char(x%10+'0');
	for (; y>0; y/=10) Y = Y + char(y%10+'0');
	Z.resize(X.size()+Y.size(),'0');
	FOR(i,0,X.size()-1) {
		int c = 0;
		FOR(j,0,Y.size()-1) {
			c += (Z[i+j]-'0') + (X[i]-'0')*(Y[j]-'0');
			Z[i+j] = char(c%10+'0');
			c /= 10;
		}
		if (c > 0) Z[i+Y.size()] += c;
	}
	ll ans = 0;
	FOD(i,Z.size()-1,0) ans = (ans*10ll + Z[i]-'0') % mod;
	return ans;
}

mat operator * (mat a, mat b) {
	mat c = {a.x, b.y};
	FOR(i,1,c.x) FOR(j,1,c.y) c.a[i][j] = 0ll;
	FOR(i,1,c.x)
	FOR(j,1,c.y)
	FOR(k,1,a.y)
	c.a[i][j] = (c.a[i][j] + solve(a.a[i][k]%mod, b.a[k][j]%mod)) % mod;
	return c;
}

mat Power(mat a, int x) {
	if (x == 1) return a;
	mat ans = Power(a, x/2);
	if (x%2) return ans * ans * a;
	return ans * ans;
}

int Test, n, T[5], F[5];
mat a, x, ans;

int main() {
	FOR(i,1,3) T[i] = i;
	FOR(i,1,3) F[i] = F[i-1] + T[i];

	a.x = 4;
	a.y = 1;
	a.a[1][1] = (ll)F[3];
	a.a[2][1] = (ll)T[3];
	a.a[3][1] = (ll)T[2];
	a.a[4][1] = (ll)T[1];

	x.x = x.y = 4;
	x.a[1][1] = x.a[1][2] = x.a[1][3] = x.a[1][4] = 1ll;
	x.a[2][2] = x.a[2][3] = x.a[2][4] = 1ll;
	x.a[3][2] = x.a[4][3] = 1ll;

	scanf("%d\n", &Test);
	while (Test--) {
		scanf("%d\n", &n);
		if (n <= 3) {
			printf("%d\n", F[n]);
			continue;
		}
		ans = Power(x, n-3) * a;
		printf("%lld\n", ans.a[1][1]);
	}


	return 0;
}