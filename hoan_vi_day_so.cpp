#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void slove(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i:a) cin >> i;
    sort(a.begin(),a.end());
    do {
        for(int i=0;i<a.size();i++){
            cout << a[i] << " ";
        }
        cout << "\n";
    } while(next_permutation(a.begin(),a.end()));
}
int main(){
    slove();
}