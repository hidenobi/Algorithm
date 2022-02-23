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
vector<string> abc;
vector<vector<vector<int>>> a(11);
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    vi v(11,0);
    v[1]++;
    v[0]=1;
    a[1].pb(v);
    FOR(i,2,10)
    {
        vi b(11,0);
        b[i]++;
        b[0]=i;
        a[i].pb(b);
        FORD(j,i-1,1)
        {
            int k=i-j;
            for (auto l:a[k])
            {
                if (j>=l[0])
                {
                    a[i].pb(l);
                    a[i][a[i].size()-1][0]=j;
                    a[i][a[i].size()-1][j]++;
                }
            }
        }
    }
    int T,n;
    cin >> T;
    while(T--)
    {
        cin >> n;
        string s="";
        for (auto i:a[n])
        {
            s=s+"(";
            FORD(j,10,1)
            {
                if (i[j]>0)
                {
                    int m=i[j];
                    string s1=to_string(j);
                    while(m>0)
                    {
                        s=s+s1+" ";
                        m--;
                    }
                }
            }
            s.pop_back();
            s=s+")";
            abc.pb(s);
            s="";
        }
        cout << abc.size() << "\n";
        for(int i=0;i<abc.size();i++) cout << abc[i] << " ";
        cout << "\n";
        abc.clear();
    }
    return 0;
 
    
}  