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
bool checkNum(int num,int digit){
    string s = to_string(num);
    return (s.find(digit + '0') == -1);
}
void slove(){
    int l,r;
    cin >> l >> r;
    int ans=0;
    queue<int> q;
    q.push(0);
    while (!q.empty())      
    {
        int front=q.front();
        q.pop();
        if(front>=l&&front<=r){
            ans++;
        }
        if(front>r) break;
        for(int i=0;i<6;i++){
            if(checkNum(front,i)) q.push(front*10+i);
        }
    }
    cout << ans << "\n";
    

}
int main(){
    int t=1;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}