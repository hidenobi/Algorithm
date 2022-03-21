#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void slove(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i:a) cin >> i;
    vector<int> lis(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>=a[j]&&lis[i]<lis[j]+1){
                lis[i]=lis[j]+1;
            }
        }
    }
    int maxx=*max_element(lis.begin(),lis.end());
    cout << n-maxx << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        slove();
    }
    return 0;
}