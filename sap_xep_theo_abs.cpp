#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
void rearrange(int arr[], int n, int x){
    multimap<int, int> m;
    multimap<int ,int >:: iterator it;
    for (int i = 0 ; i < n; i++)
        m.insert(make_pair(abs(x-arr[i]),arr[i]));
    int i = 0;
    for (it = m.begin(); it != m.end(); it++)
        arr[i++] = (*it).second ;
}
void printArray(int arr[] , int n){
    for (int i = 0 ; i < n; i++)
        cout << arr[i] << " ";
}
void slove(){
    int n,x;
    cin >> n >> x;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    rearrange(a, n, x);
    printArray(a, n);
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
