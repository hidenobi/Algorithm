#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void slove(){
    int m,n,k;
    cin >> m >> n >> k;
    vector<int> a;
    int x;
    for (int  i = 0; i < m+n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    cout << a[k-1]<<"\n";
    
}
int main(){
    int test=1;
    cin >> test;
    while(test--){
        slove();
    }
    return 0;
}