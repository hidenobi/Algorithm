#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
void slove(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x:a){
        cin >> x;
    }
    int MIN=1e9;
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(abs(a[i]+a[j])<MIN){
                sum=a[i]+a[j];
                MIN=abs(a[i]+a[j]);
            }
        }
    }
    cout << sum <<'\n';
}
int main(){
    int test=1;
    cin >> test;
    while(test--){
        slove();
    }
    return 0;
}
