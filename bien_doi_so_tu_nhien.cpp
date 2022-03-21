#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<unordered_set>
using namespace std;
long long mod = 1e9 + 7;
void slove(){
    int n;
    cin >> n;
    unordered_set<int> s;
    queue< pair<int,int> > q;
    q.push({n,0});
    s.insert(n);
    while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        if(p.first==1){
            cout << p.second << "\n";
            return;
        }
        if(s.find(p.first-1)==s.end()&&p.first>1){
            q.push({p.first-1,p.second+1});
            s.insert(p.first-1);
        }
        for(int i=2;i<=sqrt(p.first);i++){
            if(p.first%i==0){
                if(s.find(p.first/i)==s.end()){
                    q.push({p.first/i,p.second+1});
                    s.insert(p.first/i);
                }
            }
        }
    }
}
int main(){
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}