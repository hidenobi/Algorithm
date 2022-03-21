#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
using namespace std;
long long mod = 1e9 + 7;
void slove(){
    int n;
    cin >> n;
    cin.ignore();
    set<string> S;
    string s,t;
    cin >> s >> t;
    for(int i=0;i<n;i++) {
        string k;
        cin >> k;
        S.insert(k);
    }
    if(s==t) {
        cout << "0\n";
        return;
    }
    map<string,vector<string> > m;
    for(int i=0;i<s.size();i++){
        string tmp=s.substr(0,i)+"*"+s.substr(i+1);
        m[tmp].push_back(s);
    }
    for(auto it=S.begin();it!=S.end();it++){
        string tmp=*it;
        for(int j=0;j<tmp.size();j++){
            string temp=tmp.substr(0,j)+"*"+tmp.substr(j+1);
            m[temp].push_back(tmp);
        }
    }
    queue<pair<string,int> > q;
    map<string,int> vis;
    q.push({s,1});
    vis[s]=1;
    while(!q.empty()){
        pair<string,int> p=q.front();
        q.pop();
        string tmp=p.first;
        int ans=p.second;
        if(tmp==t){
            cout << ans << "\n";
            return;
        }
        for(int i=0;i<tmp.size();i++){
            string temp=tmp.substr(0,i)+"*"+tmp.substr(i+1);
            vector<string> v=m[temp];
            for(int j=0;j<v.size();j++){
                if(vis[v[j]]==0){
                    vis[v[j]]=1;
                    q.push({v[j],ans+1});
                }
            }
        }
    }
    cout << "0\n";
}
int main(){
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}