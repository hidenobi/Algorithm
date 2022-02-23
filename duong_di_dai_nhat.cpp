#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
vector<int> a[25];
bool check[25][25];
int ans=0;
void DFS(int u, int step){
    for(auto i:a[u]){
        if(!check[u][i]&&!check[i][u]){
            check[u][i]=true;
            check[i][u]=true;
            ans=max(ans,step);
            DFS(i,step+1);
            check[u][i]=false;
            check[i][u]=false;
        }
    }
}
void slove(){
    ans=0;
    memset(check,false,sizeof(check));
    for(int i=0;i<25;i++) a[i].clear();
    int n,m;
    cin >> n >> m;
    int u,v;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=0;i<25;i++){
        sort(a[i].begin(),a[i].end());
    }
    for(int i=0;i<n;i++){
        DFS(i,1);
    }
    cout << ans << "\n";
}
int main(){
    int test=1;
    cin >> test;
    while(test--){
        slove();
    }
    return 0;
}