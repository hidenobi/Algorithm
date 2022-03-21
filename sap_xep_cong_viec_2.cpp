#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Job{
   int id;     
   int dead;    
   int profit;
};
bool comparison(Job a, Job b){
    return (a.profit > b.profit);
}
void slove(){
    int n;
    cin >> n;
    vector<Job> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].id >> a[i].dead >> a[i].profit;
    }
    sort(a.begin(),a.end(),comparison);
    vector<int> ans(n);
    vector<bool> slot(n,false);
    int cnt=0,prof=0;
    for(int i=0;i<n;i++){
        while(slot[a[i].dead]&&a[i].dead>0) a[i].dead--;
        if(a[i].dead>0){
            cnt++;
            prof+=a[i].profit;
            slot[a[i].dead] = true;
        }
    }
    cout << cnt << " " << prof << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}