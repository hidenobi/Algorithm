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
void slove(){
    int n;
    cin >> n;
    queue<string> dq;
    stack<string> ans;
    dq.push("6");
    dq.push("8");
    while (dq.size())
    {
        string k = dq.front();
        ans.push(k);
        dq.pop();
        if (k.size() != n)
        {
            dq.push(k + "6");
            dq.push(k + "8");
        }
    }
    cout << ans.size() << "\n";
    while (ans.size())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;
}
int main(){
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}