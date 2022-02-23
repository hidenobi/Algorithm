#include <iostream>
#include<algorithm>
#include<vector>
#define endl "\n"
using namespace std;
void slove(){
    int n;
    cin >> n;
    vector<int> b,c,a;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(i%2==0) b.push_back(x);
        else c.push_back(x);
    }
    sort(b.begin(),b.end(),greater<int>());
    sort(c.begin(),c.end());
    int len=min(c.size(),b.size());
    for(int i=0;i<len;i++){
        a.push_back(c[i]);
        a.push_back(b[i]);
    }
    if(c.size()>len) a.push_back(c[c.size()-1]);
    for(auto i : a) cout << i << ' ';
    
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int test=1;
    while(test--){
        slove();
    }
    return 0;
	
}