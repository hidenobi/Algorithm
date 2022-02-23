#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
void slove(){
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            if(binary_search(a.begin()+j+1,a.end(),k-a[i]-a[j])==true){
                cout << "YES\n";
                return;
            }

        }
    }
    cout << "NO\n";
}
int main(){
    int test=1;
    cin >> test;
    while (test--){
        slove();
    }
    return 0;
}