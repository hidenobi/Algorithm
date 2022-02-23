#include<iostream>
#include<set>
#include<vector>
using namespace std;
void slove(){
    int n;
    cin >> n;
    set<int> a;
    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        while(x>0){
            int r=x%10;
            a.insert(r);
            x/=10;
        }
    }
    for(auto i:a) cout << i << ' ';
    cout <<'\n';

}
int main(){
    int test=1;
    cin >> test;
    while(test--){
        slove();
    }
    return 0;
}