#include <bits/stdc++.h>
#define fori(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main (){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,n,x,sum;
    bool res;
    cin>>t;
    priority_queue <int> q;
    priority_queue <int, vector<int>, greater <int> > q1;
    priority_queue <int, vector<int>, greater <int> > q2;
    while(t--){
        cin>>n;
        sum=0;
        res=1;
        fori(i,0,n){
            cin>>x;
            sum+=x;
            if(x%3==0) q.push(x);
            else if(x%3==1) q1.push(x);
            else q2.push(x);
        }
        if(sum%3==1){
            if(!q1.empty()) q1.pop();
            else{
                if(q2.size()<2) res=0;
                else {
                    q2.pop();
                    q2.pop();
                }
            }
        }
        else if(sum%3==2){
            if(!q2.empty()) q2.pop();
            else{
                if(q1.size()<2) res=0;
                else{
                    q1.pop();
                    q1.pop();
                }
            }
        }
        while(!q1.empty()){
            q.push(q1.top());
            q1.pop();
        }
        while(!q2.empty()){
            q.push(q2.top());
            q2.pop();
        }
        if(q.empty()) res=0;
        if(res){
            cout<<q.top();
            if(q.top()==0) continue;
            q.pop();
            while(!q.empty()){
                cout<<q.top();
                q.pop();
            }
        }
        else cout<<"-1";
        cout<<"\n";
    }
}