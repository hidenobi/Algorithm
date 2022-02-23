#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int check(vector<int> a){
    for(int i=0;i<a.size()-1;i++){
        if(abs(a[i]-a[i+1])==1) return 0;
    }
    return 1;
}
void slove(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    do{
        if(check(a)==1) {
            for(int i=0;i<a.size();i++) cout << a[i];
            cout << "\n";
        }
    } while(next_permutation(a.begin(),a.end()));
}
int main(){
    int t;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}