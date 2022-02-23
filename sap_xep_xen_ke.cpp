#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
void slove(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i:a) cin >> i;
    sort(a.begin(),a.end());
    vector<int> b=a;
    sort(a.begin(),a.end(),greater<int>());
    vector<int > c=a;
    a.clear();
    for(int i=0;i<n;i++){
         a.push_back(c[i]);
        if(a.size()==n) break;
        a.push_back(b[i]);
        if(a.size()==n) break;
       
    }
    for(auto i :a) cout << i << ' ';
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