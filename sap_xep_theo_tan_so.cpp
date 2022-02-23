#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second) return a.first<b.first;
    return a.second>b.second;
}
void slove(){
    int n;
    cin >> n;
    vector<int> a(n),b(100006,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[a[i]]++;
    }
    vector< pair<int,int> > v;
    for(int i=0;i<b.size();i++){
        if(b[i]!=0){
            v.push_back(make_pair(i,b[i]));
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].second;j++) cout << v[i].first << " ";
    }
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