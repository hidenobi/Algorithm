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
    queue<int> q;
    int n;
    cin >> n;
    int k;
    while (n--){
        cin >> k;
        switch (k)
        {
        case 1:
            cout << q.size() << "\n";
            break;
        case 2:
            if(!q.empty()) cout << "NO\n";
            else cout << "YES\n";
            break;
        case 3:
            int x;
            cin >> x;
            q.push(x);
            break;
        case 4:
            if(!q.empty()) q.pop();  
            break;  
        case 5:
            if(!q.empty()) cout << q.front() << "\n";
            else cout << "-1\n";
            break;
        case 6:
            if(!q.empty()) cout << q.back() << "\n";
            else cout << "-1\n";
            break;
        default:
            break;
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