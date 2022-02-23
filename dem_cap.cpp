#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
void slove(){
    int n,k;
    cin>>n>>k;
    int a[n];
    long long dem=0;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    deque <int> q;
    for(int i=0;i<n;i++)
    {
        if(q.empty()) q.push_back(a[i]);
        else if(a[i]-q.front()<k) 
        {
            dem+=q.size();
            q.push_back(a[i]);
        }
        else
        {
            while(a[i]-q.front()>=k&&!q.empty()) q.pop_front();
            dem+=q.size();
            q.push_back(a[i]);
        }
    }
    cout<<dem << "\n";
}
int main (){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}