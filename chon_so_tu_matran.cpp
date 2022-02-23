#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void slove(){
    int n,dem=0;
    cin >> n;
    vector< vector<int> > a(n),v;
    int k,x;
    cin >> k;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<n;j++){
            cin >> x;
            a[i].push_back(x);
        }
    }
    vector<int> dp(n);
    for(int i=0;i<n;i++) dp[i]=i;
    do{
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i][dp[i]];
        }
        if(sum==k){
            dem++;
            v.push_back(dp);
        }
    }while(next_permutation(dp.begin(),dp.end()));
    cout << dem << "\n";
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++) cout << v[i][j] + 1 << " ";
        cout << "\n";
    }
}
int main(){
    slove();
    return 0;
}