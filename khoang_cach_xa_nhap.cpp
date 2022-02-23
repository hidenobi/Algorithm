#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
void slove(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    int rm[n];
    rm[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        rm[i]=max(rm[i+1],a[i]);
    }
    int maxx=-1e9;
    int i=0,j=0;
    while(i<n&&j<n){
        if(rm[j]>a[i]){
            maxx=max(maxx,j-i);
            j++;
        }
        else i++;
    }
    cout << maxx << "\n";
}
int main(){
    int test=1;
    cin >> test;
    while (test--){
        slove();
    }
    return 0;
}