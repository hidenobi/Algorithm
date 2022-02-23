#include<iostream>
#include<queue>
#define ll long long
using namespace std;
void slove(){
    ll n;
    cin >> n;
    queue<ll> q;
    q.push(9);
    while(q.size()){
        ll k=q.front();
        q.pop();
        if(k%n==0){
            cout << k << "\n";
            return;
        }
        q.push(k*10);
        q.push(k*10+9);
    }
    
}
int main(){
    int test=1;
    cin >> test;
    while(test--){
        slove();
    }
    return 0;
}