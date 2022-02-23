#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
void slove(){
    int n;
    long long k; 
    cin >> n >> k;
    vector<long long> a(n),v;
    long long res=0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    sort(a.begin(),a.end());
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            long long sum = k - a[i] - a[j];
            long long low = lower_bound(a.begin()+j+1,a.end(),sum) - a.begin();
            res+=low-j-1;
            
        }
    }
    cout << res;
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
