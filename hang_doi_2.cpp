#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
using namespace std;
long long mod = 1e9 + 7;
queue<int> q;
void slove(){
    
    string s;
    cin >> s;
    if(s=="PUSH"){
        int x;
        cin >> x;
        cin.ignore();
        q.push(x);
    }
    else if(s=="PRINTFRONT"){
        if(!q.empty()) cout << q.front()<<'\n';
        else cout << "NONE\n";
    }
    else {
        if(!q.empty()) q.pop();
    }
}
int main(){
    int t=1;
    cin >> t;
    cin.ignore();
    while(t--){
        slove();
    }
    return 0;
}