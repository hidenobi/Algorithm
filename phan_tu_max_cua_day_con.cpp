#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
void slove(){
    int n,k; 
    cin >> n >> k;
    vector<int> a(n),v;
    deque<int> dq;
    for(auto &i:a) cin >> i;
    for(int i=0;i<n;i++){
        while (dq.size()&&a[dq.back()]<=a[i]) dq.pop_back();
        dq.push_back(i);
        if(dq.front()+k-1<i) dq.pop_front();
        if(i>=k-1) v.push_back(a[dq.front()]);
    }
    for(auto i:v) cout << i << " ";
    cout << "\n";
}
int main(){
    int test=1;
    cin >> test;
    while(test--){
        slove();
    }
    return 0;
}
